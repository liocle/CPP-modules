#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <list>
#include <numeric>  // For std::accumulate
#include "Colors.h"

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
    std::list<int> inputList;

    // Parse command line arguments and check for valid integers
    for (int i = 1; i < argc; ++i) {
        char* p;
        long converted = strtol(argv[i], &p, 10);
        if (*p || converted < 0 || converted > static_cast<long>(std::numeric_limits<int>::max())) {
            std::cout << RED << "Error: Invalid input. Please provide positive integers only.\n" << RESET;
            return 1;
        }
        inputVector.push_back(static_cast<int>(converted));
        inputList.push_back(static_cast<int>(converted));
    }

    std::cout << "Processing " << inputVector.size() << " elements:\t";
    for (size_t number: inputVector) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // Sort using vector
    auto startVector = std::chrono::high_resolution_clock::now();
    auto sortedVector = PmergeMe::mergeInsertSortVector(inputVector);
    auto endVector = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> vectorTime = endVector - startVector;
    std::cout << "Vector time to process:\t" << vectorTime.count() << " us\n";

    // Sort using list
    auto startList = std::chrono::high_resolution_clock::now();
    auto sortedList = PmergeMe::mergeInsertSortList(inputList);
    auto endList = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> listTime = endList - startList;
    std::cout << "List time to process:\t" << listTime.count() << " us\n";

    //
    // Statistics and integrity checks for Vector
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

    std::cout << "Unsorted vector:\t";
    for (size_t number: inputVector) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    if (inputVector.size() < 50) {
        std::cout << "Sorted vector:\t\t";
        for (int num : sortedVector) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    // Statistics and integrity checks for list
    std::cout << CYAN << "\n----- Statistics and integrity check for list ----\n" << RESET;
    std::cout << "Input list size:	" << inputList.size() << std::endl;
    std::cout << "Sorted list size:	" << sortedList.size() << std::endl;

    size_t sumInputList = std::accumulate(inputList.begin(), inputList.end(), 0);
    size_t sumSortedList = std::accumulate(sortedList.begin(), sortedList.end(), 0);
    std::cout << "Sum of input list:	" << sumInputList << std::endl;
    std::cout << "Sum of sorted list:	" << sumSortedList << std::endl;
    bool sortedCheckList = isSorted(sortedList);
    std::cout << "Is the list sorted?\t" << (sortedCheckList? GREEN "Yes" : RED "No") << std::endl;

    if (sumInputList == sumSortedList && inputVector.size() == sortedVector.size()) {
        std::cout << GREEN << "No numbers were dropped or changed during sorting." << RESET << std::endl;
    } else {
        std::cout << RED << "Error: Data mismatch detected!" << RESET << std::endl;
    }

    std::cout << "Unsorted list:\t\t";
    for (size_t number: inputList) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    if (inputList.size() < 50) {
        std::cout << "Sorted list:\t\t";
        for (int num : sortedList) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

