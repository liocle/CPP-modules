#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <list>
#include <numeric>  // For std::accumulate

bool isSorted(const std::vector<int>& data) {
    return std::is_sorted(data.begin(), data.end());
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Error: No numbers provided.\n";
        return 1;
    }

    std::vector<int> inputVector;
    std::list<int> inputList;

    // Parse command line arguments and check for valid integers
    for (int i = 1; i < argc; ++i) {
        char* p;
        long converted = strtol(argv[i], &p, 10);
        if (*p || converted < 0 || converted > static_cast<long>(std::numeric_limits<int>::max())) {
            std::cout << "Error: Invalid input. Please provide positive integers only.\n";
            return 1;
        }
        inputVector.push_back(static_cast<int>(converted));
        inputList.push_back(static_cast<int>(converted));
    }

    std::cout << "Processing " << inputVector.size() << " elements: ";
    for (size_t number: inputVector) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // Sort using vector
    auto startVector = std::chrono::high_resolution_clock::now();
    auto sortedVector = PmergeMe::mergeInsertSortVector(inputVector);
    auto endVector = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> vectorTime = endVector - startVector;

    std::cout << "Time to process: " << vectorTime.count() << " us\n";
    bool sortedCheck = isSorted(sortedVector);
    std::cout << "Is the list sorted? " << (sortedCheck ? "Yes" : "No") << std::endl;

    // Statistics and integrity checks
    std::cout << "Input list size: " << inputVector.size() << std::endl;
    std::cout << "Sorted list size: " << sortedVector.size() << std::endl;

    size_t sumInput = std::accumulate(inputVector.begin(), inputVector.end(), 0);
    size_t sumSorted = std::accumulate(sortedVector.begin(), sortedVector.end(), 0);
    std::cout << "Sum of input list: " << sumInput << std::endl;
    std::cout << "Sum of sorted list: " << sumSorted << std::endl;

    if (sumInput == sumSorted && inputVector.size() == sortedVector.size()) {
        std::cout << "No numbers were dropped or changed during sorting." << std::endl;
    } else {
        std::cout << "Error: Data mismatch detected!" << std::endl;
    }

    if (inputVector.size() < 50) {
        std::cout << "Sorted list: ";
        for (int num : sortedVector) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

