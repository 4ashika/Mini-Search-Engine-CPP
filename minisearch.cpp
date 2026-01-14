#include "minisearch.h"
#include "trie.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>

namespace fs = std::filesystem;

// Check for the MiniSearch:: prefix!
std::string MiniSearch::cleanWord(std::string word) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
        return !std::isalnum(c);
    }), word.end());
    return word;
}

void MiniSearch::loadDatasets(std::string path) {
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            totalDocs++;

            std::string fileName = entry.path().filename().string();
            std::ifstream file(entry.path());
            std::string word;

            while (file >> word) {
                std::string cleaned = cleanWord(word);
                if (!cleaned.empty()) {
                    // This increments the count for this word in this specific file
                    invertedIndex[cleaned][fileName]++;
                    suggestor.insert(cleaned);
                }
            }
        }
    }
    std::cout << "Indexing complete! Total unique words: " << invertedIndex.size() << std::endl;
}

void MiniSearch::search(std::string query) {
    std::string cleaned = cleanWord(query);
    
    if (invertedIndex.find(cleaned) == invertedIndex.end()) {
        std::cout << "No results found." << std::endl;
        return;
    }

    std::vector<SearchResult> results;
    double idf = log((double)totalDocs / (double)invertedIndex[cleaned].size());

    for (auto const& [file, count] : invertedIndex[cleaned]) {
        // Simple TF-IDF score: (Count in this file) * (Rarity across all files)
        double score = count * idf;
        results.push_back({file, score});
    }

    // Sort results by score (descending)
    std::sort(results.begin(), results.end(), [](const SearchResult& a, const SearchResult& b) {
        return a.score > b.score;
    });

    std::cout << "\nRanked Results for '" << query << "':" << std::endl;
    for (const auto& res : results) {
        printf("- %-15s | Score: %.4f\n", res.fileName.c_str(), res.score);
    }
}

void MiniSearch::autocomplete(std::string partial) {
    // 1. Clean the input (lowercase it)
    std::string cleaned = cleanWord(partial);
    
    if (cleaned.empty()) return;

    // 2. Query the Trie suggestor
    std::vector<std::string> suggestions = suggestor.getSuggestions(cleaned);

    // 3. Display results
    if (suggestions.empty()) {
        std::cout << "No suggestions found for '" << partial << "'" << std::endl;
    } else {
        std::cout << "\n--- Suggestions for '" << partial << "' ---" << std::endl;
        for (size_t i = 0; i < suggestions.size() && i < 5; ++i) { // Limit to top 5
            std::cout << "  > " << suggestions[i] << std::endl;
        }
    }
}