#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <string>
#include <vector>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
};

class Trie {
public:
    Trie();
    void insert(std::string word);
    std::vector<std::string> getSuggestions(std::string prefix);

private:
    TrieNode* root;
    void findWords(TrieNode* node, std::string currentPrefix, std::vector<std::string>& results);
};

#endif