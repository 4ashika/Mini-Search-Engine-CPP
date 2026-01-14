#include <iostream>
#include "minisearch.h"

int main() {
    MiniSearch engine;
    std::cout << "--- Initializing Search Engine ---" << std::endl;
    engine.loadDatasets("./datasets");

    int choice;
    std::string input;

    while (true) {
        std::cout << "\n1. Search | 2. Autocomplete | 3. Exit\nChoose: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character

        if (choice == 3) break;

        std::cout << "Enter text: ";
        std::getline(std::cin, input);

        if (choice == 1) {
            engine.search(input);
        } else if (choice == 2) {
            engine.autocomplete(input);
        }
    }

    return 0;
}