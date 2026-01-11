#include "minisearch.h"
#include <iostream>
#include <fstream>
#include <algorithm>

namespace fs = std::filesystem;

std::string MiniSearch::cleanWord(std::string word)
{
  // Lowercase
  std::transform(word.begin(), word.end(), word.begin(), ::tolower);
  // Remove punctuation
  word.erase(std::remove_if(word.begin(), word.end(), [](char c)
                            { return !std::isalnum(c); }),
             word.end());
  return word;
}

void MiniSearch::loadDatasets(std::string path)
{
  for (const auto &entry : fs::directory_iterator(path))
  {
    if (entry.is_regular_file())
    {
      fileNames.push_back(entry.path().string());
      std::cout << "Detected: " << entry.path().filename() << std::endl;

      // For Day 1 test: Just open and print the first 5 words
      std::ifstream file(entry.path());
      std::string word;
      int count = 0;
      while (file >> word && count < 5)
      {
        std::cout << "  Word: " << cleanWord(word) << std::endl;
        count++;
      }
    }
  }
}
