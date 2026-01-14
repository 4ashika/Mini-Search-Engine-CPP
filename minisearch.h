#include <unordered_map>
#include <map>
#include <string>
#include <cmath>

struct SearchResult {
    std::string fileName;
    double score;
};

class MiniSearch {
public:
    void loadDatasets(std::string path);
    std::string cleanWord(std::string word);
    void search(std::string query); // We'll add this today!

private:
    std::unordered_map<std::string, std::map<std::string, int>> invertedIndex;
    int totalDocs = 0; // Track total files for IDF calculation
};