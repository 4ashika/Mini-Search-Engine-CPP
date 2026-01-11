#ifndef MINISEARCH_H
#define MINISEARCH_H

#include <string>
#include <vector>
#include <set>
#include <filesystem>

class MiniSearch {
public:
    // Reads all files in the directory
    void loadDatasets(std::string path);
    
    // Cleans words (removes symbols, lowercase)
    std::string cleanWord(std::string word);

private:
    std::vector<std::string> fileNames; // List of files we've indexed
};

#endif