#ifndef MINISEARCH_H
#define MINISEARCH_H

#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <map>
#include "trie.h"

struct SearchResult {
    std::string fileName;
    double score;
};

class MiniSearch {
public:
    void loadDatasets(std::string path);
    std::string cleanWord(std::string word);
    void search(std::string query);
    void autocomplete(std::string partial);

private:
    std::unordered_map<std::string, std::map<std::string, int>> invertedIndex;
    int totalDocs = 0; // Track total files for IDF calculation
    Trie suggestor;
};

#endif