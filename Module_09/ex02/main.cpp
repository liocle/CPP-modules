#include <chrono>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <vector>
#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Error: No numbers provided.\n";
        return 1;
    }

    std::vector<int> inputVector;
    std::list<int> inputList;

    // Parse command line arguments and check for valid positive integers
    for (int i = 1; i < argc; ++i) {
        char* p;
        long converted = strtol(argv[i], &p, 10);
        if (*p || converted < 1) {
            std::cout << "Error: Invalid input. Please provide positive integers only.\n";
            return 1;
        }
        if (converted > static_cast<long>(std::numeric_limits<int>::max())) {
            std::cout << "Error: Invalid input. Please provide positive integers only.\n";
            return 1;
        }
        inputVector.push_back(converted);
        inputList.push_back(converted);
    }

    // Display unsorted data
    std::cout << "Before: ";
    for (int num : inputVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort using vector
    auto startVector = std::chrono::high_resolution_clock::now();
    auto sortedVector = PmergeMe::mergeInsertSortVector(inputVector);
    auto endVector = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> vectorTime = endVector - startVector;

    std::cout << "Time to process a range of " << inputVector.size() << " elements with std::vector: " << vectorTime.count() << " us"
              << std::endl;

    // // Sort using list
    // auto startList = std::chrono::high_resolution_clock::now();
    // auto sortedList = PmergeMe::mergeInsertSortList(inputList);
    // auto endList = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double, std::micro> listTime = endList - startList;
    // std::cout << " test " << std::endl;
    // std::cout << "Time to process a range of " << inputList.size() << " elements with std::list: " << listTime.count() << " us" << std::endl;

    // Display sorted data from vector
    std::cout << "After: ";
    for (int num : sortedVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
