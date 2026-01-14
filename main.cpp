#include <iostream>
#include "minisearch.h"
#include "trie.h"

int main() {
    MiniSearch engine;
    engine.loadDatasets("./datasets");

    std::string query = "lo"; // Test with a prefix
    std::cout << "User is typing: " << query << "..." << std::endl;
    
    engine.autocomplete(query); 

    return 0;
}