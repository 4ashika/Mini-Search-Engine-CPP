#include <iostream>
#include "minisearch.h"

int main() {
    MiniSearch engine;
    engine.loadDatasets("./datasets");
    engine.search("in"); // Or any word in your Abstract.txt
    return 0;
}