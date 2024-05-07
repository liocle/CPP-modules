#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

SortContext context;  // if input contains odd amount of data, this will be set to the last value, else flagged as non used with INT_MIN

/**
 * @brief Helper function to perform binary insertion for vectors
 */
void binaryInsertVector(std::vector<int>& mainChain, int value) {
    std::cout << "\t\t-- Inserting value " << value << " into the main chain" << std::endl;
    auto it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
    mainChain.insert(it, value);
    std::cout << "\t\t--> Main chain after insertion: ";
    for (int val : mainChain) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

/**
 * @brief  Helper function for merging sorted pairs of larger values
 *
 */
void PmergeMe::mergeInsertPairsLargerValues(std::vector<std::pair<int, int>>& vectorOfPairs, unsigned int left, unsigned int right) {
    if (left >= right) {
        std::cout << "\t! No merge needed between left " << left << " and right " << right << "\n";
        return;
    }

    // Find the middle point
    unsigned int mid = (left + right) / 2;
    std::cout << "\t-> Merging from left " << left << " to mid " << mid << " and mid+1 " << mid + 1 << " to right " << right << "\n";

    // Recursively divide and sort both halves
    mergeInsertPairsLargerValues(vectorOfPairs, left, mid);
    mergeInsertPairsLargerValues(vectorOfPairs, mid + 1, right);

    // Merging sorted pairs by their larger values
    std::vector<std::pair<int, int>> temp;
    unsigned int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (context.hasOddLastElement == false) {  // if input amount is odd, specify that last pair should not be merged
            if (vectorOfPairs[i].first <= vectorOfPairs[j].first) {
                temp.push_back(vectorOfPairs[i]);
                ++i;
            } else {
                temp.push_back(vectorOfPairs[j]);
                ++j;
            }
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

    std::cout << "\t-> Vector after merging: ";
    for (const auto& pair : vectorOfPairs) {
        std::cout << "(" << pair.first << "," << pair.second << ") ";
    }
    std::cout << "\n";
}

/**
 * @brief binary insertion of pairs' second member
 *
 */
void PmergeMe::binaryInsertSmallerValues(std::vector<std::pair<int, int>>& vectorOfPairs, std::vector<int>& mainChain,
                                         SortContext context) {
    size_t j = 0;
    std::cout << "\t * Prior Binary insertion, feed main chain starting from first pair\n";

    mainChain.push_back(vectorOfPairs[j].second);  // second member of first pair is known to be smaller than first member
    mainChain.push_back(vectorOfPairs[j].first);
    std::cout << "\t * First pair (" << vectorOfPairs[j].first << ", " << vectorOfPairs[j].second << ") was inserted in main chain:\n\t * ";
    j++;  // lets move to second pair of vectorOfPairs

    for (int number : mainChain) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    std::cout << "\t * Fill up main chain with pair's first larger member, processing pairs: ";
    //fill up sorted larger pair first members to mainChain
    for (size_t i = j; i < vectorOfPairs.size(); ++i) {
    std::cout << " (" << vectorOfPairs[i].second << ", " << vectorOfPairs[i].first << ") ";
        mainChain.push_back(vectorOfPairs[i].first);
    }
    std::cout << "Main chain contains now larger values from pairs + first pair second member: ";

    for (int number : mainChain) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // Ford and Johnson generalization for first half of list of Demuth five element sorting
    for (; j <= (vectorOfPairs.size() - 1) / 2;
         ++j) {  // until first half of amount of pairs, handle vectorOfPairs[j+1].second, then vectorofParis[j].second.
        if (j + 1 <= (vectorOfPairs.size() - 1) / 2) {
            binaryInsertVector(mainChain, vectorOfPairs[j + 1].second);
        }
        binaryInsertVector(mainChain, vectorOfPairs[j].second);
    }
    if (context.hasOddLastElement == true) {
        binaryInsertVector(mainChain, context.oddLastElement);
    }
    for (size_t k = vectorOfPairs.size() - 1; k > (vectorOfPairs.size() - 1) / 2; --k) {
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

    size_t i = 0;

    std::vector<std::pair<int, int>> vectorOfPairs;  // Declare vector of pairs
    for (; i < input.size(); i += 2) {               // fill pairs with input
        if (i + 1 < input.size()) {
            if (input[i] >= input[i + 1]) {  // sort first and second members of pairs, larger values populate first member.
                vectorOfPairs.push_back(std::make_pair(input[i], input[i + 1]));
            } else {
                vectorOfPairs.push_back(std::make_pair(input[i + 1], input[i]));
            }
        } else {
            context.hasOddLastElement = true;
            context.oddLastElement = input.back();  // if input amount is odd, last input will be handled specifically, as per Ford Johnson
        }
    }

    unsigned int vectorStartIndex = 0;
    unsigned int vectorLastIndexEvenCase = vectorOfPairs.size() - 1;
    mergeInsertPairsLargerValues(vectorOfPairs, vectorStartIndex, vectorLastIndexEvenCase);

    std::vector<int> mainChain;
    binaryInsertSmallerValues(vectorOfPairs, mainChain, context);

    return mainChain;
}
