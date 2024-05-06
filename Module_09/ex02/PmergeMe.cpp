#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

// Helper function to perform binary insertion for vectors
void binaryInsertVector(std::vector<int>& mainChain, int value) {
    auto it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
    mainChain.insert(it, value);
}

// // Helper function to perform binary insertion for lists
// template <typename T>
// void binaryInsertList(T &container, typename T::value_type value) {
//   auto it = std::find_if(
//       container.begin(), container.end(),
//       [&](const typename T::value_type &elem) { return value < elem; });
//   container.insert(it, value);
// }

// Helper function for merging sorted pairs of larger values
void PmergeMe::mergeInsertPairsLargerValues(std::vector<std::pair<int, int>>& vectorOfPairs, unsigned int left, unsigned int right) {
    if (left >= right)
        return;

    // Find the middle point
    unsigned int mid = (left + right) / 2;

    // Recursively divide and sort both halves
    mergeInsertPairsLargerValues(vectorOfPairs, left, mid);
    mergeInsertPairsLargerValues(vectorOfPairs, mid + 1, right);

    // Merging sorted pairs by their larger values
    std::vector<std::pair<int, int>> temp;
    unsigned int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (vectorOfPairs[i].first <= vectorOfPairs[j].first) {
            temp.push_back(vectorOfPairs[i]);
            ++i;
        } else {
            temp.push_back(vectorOfPairs[j]);
            ++j;
        }
    }

    // Append remaining elements from either half
    while (i <= mid) {
        temp.push_back(vectorOfPairs[i]);
        ++i;
    }

    while (j <= right) {
        temp.push_back(vectorOfPairs[j]);
        ++j;
    }

    // Move sorted pairs back to the original vector
    for (unsigned int k = 0; k < temp.size(); ++k) {
        vectorOfPairs[left + k] = temp[k];
    }
}

void PmergeMe::binaryInsertSmallerValues(std::vector<std::pair<int, int>>& vectorOfPairs, std::vector<int> &mainChain) {
    size_t j = 0;                                  // j of the vectorOfPairs
    mainChain.push_back(vectorOfPairs[j].second);  // second pair member is smaller than first
    mainChain.push_back(vectorOfPairs[j].first);
    j++;  // lets move to second pair of vectorOfPairs

    //fill up sorted larger pair members to mainChain
    for(size_t i = j; i <= vectorOfPairs.size(); ++i) {
        mainChain.push_back(vectorOfPairs[i].first);
    }
    
    // Ford and Johnson generalization for first half of list of Demuth five element sorting
    for (;j + 1 <= (vectorOfPairs.size() - 1) / 2; ++j) { // until first half of amount of pairs, handle vectorOfPairs[j+1].second, then vectorofParis[j].second.
        binaryInsertVector(mainChain, vectorOfPairs[j + 1].second);
        binaryInsertVector(mainChain, vectorOfPairs[j].second);
    }
    for(size_t k = vectorOfPairs.size() - 1; k > (vectorOfPairs.size() - 1)/2; --k) {
        binaryInsertVector(mainChain, vectorOfPairs[k].second);
    }
}

/**
  * @brief  Merge-insertion sort for vector
  *
  */
std::vector<int> PmergeMe::mergeInsertSortVector(const std::vector<int>& input) {
    if (input.size() <= 1) {
        return input;
    }

    std::vector<std::pair<int, int>> vectorOfPairs;  // Declare vector of pairs
    for (size_t i = 0; i < input.size(); i += 2) {   // fill pairs with input
        if (i + 1 <= input.size()) {
            if (input[i] >= input[i + 1]) {  // sort first and second members of pairs,
                                             // larger values populate first member.
                vectorOfPairs.push_back(std::make_pair(input[i], input[i + 1]));
            } else {
                vectorOfPairs.push_back(std::make_pair(input[i + 1], input[i]));
            }
        } else {
            vectorOfPairs.back().first = input[i];  // if input contains odd number, last value is sorted and
                                                    // set to first position
        }
    }

    unsigned int vectorStartIndex = 0;
    unsigned int vectorLastIndex = vectorOfPairs.size() - 1;
    mergeInsertPairsLargerValues(vectorOfPairs, vectorStartIndex, vectorLastIndex);

    std::vector<int> mainChain;
    binaryInsertSmallerValues(vectorOfPairs, mainChain);

    // std::vector<int> sortedAList = mergeInsertSortVector(aList); // Recursive
    // sort for (const auto &b : bList) {
    //   binaryInsertVector(sortedAList, b);
    // }

    return mainChain;
}

// // Merge-insertion sort for list
// std::list<int> PmergeMe::mergeInsertSortList(const std::list<int> &arr) {
//   if (arr.size() <= 1) {
//     return arr;
//   }

//   std::list<int> aList, bList;
//   auto it = arr.begin();
//   while (it != arr.end()) {
//     auto next = std::next(it);
//     if (next != arr.end()) {
//       if (*it < *next) {
//         bList.push_back(*it);
//         aList.push_back(*next);
//         ++next;
//       } else {
//         bList.push_back(*next);
//         aList.push_back(*it);
//       }
//       ++it; // Move to the next pair
//     } else {
//       aList.push_back(*it); // Odd element
//     }
//     it = next;
//   }

//   std::list<int> sortedAList = mergeInsertSortList(aList); // Recursive sort
//   for (const auto &b : bList) {
//     binaryInsertList(sortedAList, b);
//   }
//   std::cout << "MergeInsertSortList: test " << std::endl;

//   return sortedAList;
// }
