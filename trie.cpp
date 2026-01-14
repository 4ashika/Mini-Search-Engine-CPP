#include "trie.h"

Trie::Trie() { root = new TrieNode(); }

void Trie::insert(std::string word) {
    TrieNode* curr = root;
    for (char ch : word) {
        if (curr->children.find(ch) == curr->children.end()) {
            curr->children[ch] = new TrieNode();
        }
        curr = curr->children[ch];
    }
    curr->isEndOfWord = true;
}

// Helper function to find all words starting from a node
void Trie::findWords(TrieNode* node, std::string currentPrefix, std::vector<std::string>& results) {
    if (node->isEndOfWord) results.push_back(currentPrefix);
    for (auto const& [ch, child] : node->children) {
        findWords(child, currentPrefix + ch, results);
    }
}

std::vector<std::string> Trie::getSuggestions(std::string prefix) {
    TrieNode* curr = root;
    for (char ch : prefix) {
        if (curr->children.find(ch) == curr->children.end()) return {};
        curr = curr->children[ch];
    }
    std::vector<std::string> results;
    findWords(curr, prefix, results);
    return results;
}