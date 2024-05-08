#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <numeric>  // For std::accumulate
#include <vector>
#include "Colors.h"
#include "PmergeMe.hpp"

template <typename T>
bool isSorted(const T& data) {
    return std::is_sorted(data.begin(), data.end());
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << RED << "Error: No numbers provided.\n" << RESET;
        return 1;
    }

    std::vector<int> inputVector;
    std::deque<int> inputDeque;

    // Parse command line arguments and check for valid integers
    for (int i = 1; i < argc; ++i) {
        char* p;
        long converted = strtol(argv[i], &p, 10);
        if (*p || converted < 0 || converted > static_cast<long>(std::numeric_limits<int>::max())) {
            std::cout << RED << "Error: Invalid input. Please provide positive integers only.\n" << RESET;
            return 1;
        }
        inputVector.push_back(static_cast<int>(converted));
        inputDeque.push_back(static_cast<int>(converted));
    }

    std::cout << YELLOW << "Processing " << inputVector.size() << " elements:\t";
    for (size_t number : inputVector) {
        std::cout << number << " ";
    }
    std::cout << RESET << std::endl;

    // Sort using vector
    SortContext contextVector;
    auto startVector = std::chrono::high_resolution_clock::now();
    auto sortedVector = PmergeMe::mergeInsertSort(inputVector, contextVector);
    auto endVector = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> vectorTime = endVector - startVector;
    std::cout << YELLOW << "Vector time to process:\t" << RESET << vectorTime.count() << " us\n" << RESET;
    std::cout << "Comparison made:\t" << contextVector.comparisons << std::endl;

    // Sort using list
    SortContext contextDeque;
    auto startDeque = std::chrono::high_resolution_clock::now();
    auto sortedDeque = PmergeMe::mergeInsertSort(inputDeque, contextDeque);
    auto endDeque = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> dequeTime = endDeque - startDeque;
    std::cout << YELLOW << "Deque time to process:\t" << RESET << dequeTime.count() << " us\n" << RESET;
    std::cout << "Comparison made:\t" << contextDeque.comparisons << std::endl;

    std::cout << "Fastest container:\t";
    if (vectorTime.count() <= dequeTime.count()) {
        double speedup = (dequeTime.count() / vectorTime.count() - 1) * 100;
        std::cout << YELLOW << "vector wins by " << std::fixed << std::setprecision(2) << speedup << "%\n" << RESET;
    } else {
        double speedup = (vectorTime.count() / dequeTime.count() - 1) * 100;
        std::cout << YELLOW << "deque wins by " << std::fixed << std::setprecision(2) << speedup << "%\n" << RESET;
    }

    // ---- Statistics and integrity checks for Vector ----
    std::cout << CYAN << "\n----- Statistics and integrity check for vector ----\n" << RESET;
    std::cout << "Input vector size:	" << inputVector.size() << std::endl;
    std::cout << "Sorted vector size:	" << sortedVector.size() << std::endl;

    size_t sumInputVector = std::accumulate(inputVector.begin(), inputVector.end(), 0);
    size_t sumSortedVector = std::accumulate(sortedVector.begin(), sortedVector.end(), 0);
    std::cout << "Sum of input vector:	" << sumInputVector << std::endl;
    std::cout << "Sum of sorted vector:	" << sumSortedVector << std::endl;
    bool sortedCheckVector = isSorted(sortedVector);
    std::cout << "Is the vector sorted? " << (sortedCheckVector ? GREEN "\tYes" : RED "\tNo") << RESET << std::endl;

    if (sumInputVector == sumSortedVector && inputVector.size() == sortedVector.size()) {
        std::cout << GREEN << "No numbers were dropped or changed during sorting." << RESET << std::endl;
    } else {
        std::cout << RED << "Error: Data mismatch detected!" << RESET << std::endl;
    }

    // Print unsorted / sorted vectors
    size_t maxElementToPrint = 100;
    if (inputDeque.size() < maxElementToPrint) {
        std::cout << "Unsorted vector:\t";
        for (size_t number : inputVector) {
            std::cout << number << " ";
        }
        std::cout << std::endl;
    }
    if (inputVector.size() < maxElementToPrint) {
        std::cout << YELLOW << "Sorted vector:\t\t" << RESET;
        for (int num : sortedVector) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << YELLOW << "Currently limitating printing of unsorted and sorted list to " << maxElementToPrint << " elements\n"
                  << RESET;
    }

    // ----- Statistics and integrity checks for list -----
    std::cout << CYAN << "\n----- Statistics and integrity check for list ----\n" << RESET;
    std::cout << "Input list size:	" << inputDeque.size() << std::endl;
    std::cout << "Sorted list size:	" << sortedDeque.size() << std::endl;

    size_t sumInputDeque = std::accumulate(inputDeque.begin(), inputDeque.end(), 0);
    size_t sumSortedDeque = std::accumulate(sortedDeque.begin(), sortedDeque.end(), 0);
    std::cout << "Sum of input list:	" << sumInputDeque << std::endl;
    std::cout << "Sum of sorted list:	" << sumSortedDeque << std::endl;
    bool sortedCheckDeque = isSorted(sortedDeque);
    std::cout << "Is the list sorted?\t" << (sortedCheckDeque ? GREEN "Yes" : RED "No") << std::endl;

    if (sumInputDeque == sumSortedDeque && inputVector.size() == sortedVector.size()) {
        std::cout << GREEN << "No numbers were dropped or changed during sorting." << RESET << std::endl;
    } else {
        std::cout << RED << "Error: Data mismatch detected!" << RESET << std::endl;
    }

    // Print unsorted / sorted lists
    if (inputDeque.size() < maxElementToPrint) {
        std::cout << "Unsorted list:\t\t";
        for (size_t number : inputDeque) {
            std::cout << number << " ";
        }
        std::cout << std::endl;
        if (inputDeque.size() < maxElementToPrint) {
            std::cout << YELLOW << "Sorted list:\t\t" << RESET;
            for (int num : sortedDeque) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << YELLOW << "Currently limitating printing of unsorted and sorted list to " << maxElementToPrint << " elements\n"
                  << RESET;
    }

    return 0;
}
