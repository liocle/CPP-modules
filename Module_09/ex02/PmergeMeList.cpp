#include <algorithm>
#include <iostream>
#include "PmergeMe.hpp"

/**
 * @brief Helper function to perform binary insertion for lists
 */
void PmergeMe::listBinaryInsertList(std::list<int>& mainChain, int value) {
    // std::cout << "\t-- Inserting value " << value << " into the main chain" << std::endl;
    auto it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
    mainChain.insert(it, value);
    // std::cout << "\t\t--> Main chain after insertion: [ ";
    // for (int val : mainChain) {
    //     std::cout << val << " ";
    // }
    // std::cout << "]\n";
}

/**
 * @brief  Helper function for merging sorted pairs of larger values
 *
 */
void PmergeMe::listMergeInsertPairsLargerValues(std::list<std::pair<int, int>>& listOfPairs, SortContext context) {
    if (listOfPairs.size() <= 1) {  // base case for the recursion
        return;
    }

    // Find the middle point
    auto mid = std::next(listOfPairs.begin(), listOfPairs.size() / 2);
    std::list<std::pair<int, int>> leftHalf(listOfPairs.begin(), mid);
    std::list<std::pair<int, int>> rightHalf(mid, listOfPairs.end());

    // Recursively divide and sort both halves
    listMergeInsertPairsLargerValues(leftHalf, context);
    listMergeInsertPairsLargerValues(rightHalf, context);

    // Merge two halves
    auto leftIt = leftHalf.begin();
    auto rightIt = rightHalf.begin();
    auto insertPos = listOfPairs.begin();

    while (leftIt != leftHalf.end() && rightIt != rightHalf.end()) {
        if (leftIt->first <= rightIt->first) {
            *insertPos = *leftIt;
            ++leftIt;
        } else {
            *insertPos = *rightIt;
            ++rightIt;
        }
        ++insertPos;
    }

    // Append remaining elements from either half
    while (leftIt != leftHalf.end()) {
        *insertPos++ = *leftIt++;
    }

    while (rightIt != rightHalf.end()) {
        *insertPos++ = *rightIt++;
    }

    // std::cout << "\t-> list after merging: ";
    // for (const auto& pair : listOfPairs) {
    //     std::cout << "(" << pair.first << "," << pair.second << ") ";
    // }
    // std::cout << "\n";
}

/**
 * @brief binary insertion of pairs' second member
 *
 */
void PmergeMe::listBinaryInsertSmallerValues(std::list<std::pair<int, int>>& listOfPairs, std::list<int>& mainChain, SortContext context) {
    // std::cout << "\t * Prior Binary insertion, feed main chain starting from first pair\n";

    auto pairIt = listOfPairs.begin();
    mainChain.push_back(pairIt->second);  // second member of first pair is known to be smaller than first member
    mainChain.push_back(pairIt->first);
    // std::cout << "\t * First pair (" << listOfPairs[j].first << ", " << listOfPairs[j].second << ") was inserted in main chain: [ ";
    pairIt++;  // lets move to second pair of listOfPairs

    // for (int number : mainChain) {
    //     std::cout << number << " ";
    // }
    // std::cout << "]\n";

    // std::cout << "\t * Fill up main chain with pair's first larger member, processing pairs:\n\t   -> ";
    // fill up sorted larger pair first members to mainChain
    for (auto tempIt = pairIt; tempIt != listOfPairs.end(); ++tempIt) {
        // std::cout << "(" << listOfPairs[i].first << ", " << listOfPairs[i].second << ") ";
        mainChain.push_back(tempIt->first);
    }
    // std::cout << "\n\t * Main chain contains now larger values from pairs + first pair's second member:\n\t    -> [";
    // for (int number : mainChain) {
    //     std::cout << number << " ";
    // }
    // std::cout << "]\n\t";
    // std::cout << "Pairs' first members (n/2) + first pair's second member are in main chain (n/2 + 1) = " << mainChain.size();
    // std::cout << " <- Expected n = " << listOfPairs.size() + 1 << std::endl;

    // Ford and Johnson generalization for first half of list of Demuth five element sorting
    auto mid = std::next(listOfPairs.begin(), (listOfPairs.size() - 1) / 2);
    for (; pairIt != mid; ++pairIt) {  // until first half of amount of pairs, handle listOfPairs[j+1].second, then listofPairs[j].second.
        auto pairItNext = pairIt;
        pairItNext++;
        if (pairItNext != mid) {
            // std::cout << "\t###1/2### Problematic insert: j = " << j
            //           << " (listOfPairs.size() -1 ) / 2 = " << (listOfPairs.size() - 1) / 2 << " current pair.second"
            //           << listOfPairs[j].second << std::endl;
            // std::cout << "\t###2/2### Problematic insert: j + 1 = " << j + 1
            //           << " (listOfPairs.size() -1 ) / 2 = " << (listOfPairs.size() - 1) / 2 << " current pair.second"
            //           << listOfPairs[j + 1].second << std::endl;
            listBinaryInsertList(mainChain, pairItNext->second);
            listBinaryInsertList(mainChain, pairIt->second);
            pairIt++;
        } else {
            // std::cout << "\t### Problematic insert: j = " << j << " (listOfPairs.size() -1 ) / 2 = " << (listOfPairs.size() - 1) / 2
            //           << " current pair.second" << listOfPairs[j].second << std::endl;
            listBinaryInsertList(mainChain, pairIt->second);
        }
    }
    // std::cout << "\n\t * Binary inserted remaining first half of pairs' second member to main chain ";
    // for (int number : mainChain) {
    //     std::cout << number << " ";
    // }
    // std::cout << "\n";

    if (context.hasOddLastElement == true) {
        listBinaryInsertList(mainChain, context.oddLastElement);
        // std::cout << "\n\t * Binary inserted oddLastElement: \"" << context.oddLastElement << "\" main chain contains:\n\t   -> ";
        // for (int number : mainChain) {
        //     std::cout << number << " ";
        // }
    }

    // std::cout << "\n\t * Binary inserting remaining pairs second member:\n\t ";
    for (size_t k = listOfPairs.size() - 1; k > (listOfPairs.size() - 1) / 2; --k) {
        // std::cout << " (" << listOfPairs[k].first << ", " << listOfPairs[k].second << ") ";
        listBinaryInsertList(mainChain, pairIt->second);
    }
    // std::cout << "\n\t * Main chain contains now:\n\t   -> ";
    // for (int number : mainChain) {
    //     std::cout << number << " ";
    // }
    // std::cout << std::endl;
}

/**
  * @brief  Merge-insertion sort for list
  *
  */
std::list<int> PmergeMe::mergeInsertSortList(const std::list<int>& input) {
    if (input.size() <= 1) {
        return input;
    }

    size_t i = 0;
    SortContext context;  // if input contains odd amount of data, this will be set to the last value

    std::list<std::pair<int, int>> listOfPairs;  // Declare list of pairs
    auto inputIt = input.begin();
    auto inputItNext = inputIt;
    inputItNext++;
    for (; inputIt != input.end(); inputIt = std::next(inputIt, 2)) {  // fill pairs with input
        if (i + 1 < input.size()) {
            if (*inputIt >= *inputItNext) {  // sort first and second members of pairs, larger values populate first member.
                listOfPairs.push_back(std::make_pair(*inputIt, *inputItNext));
            } else {
                listOfPairs.push_back(std::make_pair(*inputItNext, *inputIt));
            }
        } else {
            context.hasOddLastElement = true;
            context.oddLastElement = input.back();  // if input amount is odd, last input will be handled specifically, as per Ford Johnson
        }
    }

    listMergeInsertPairsLargerValues(listOfPairs, context);

    std::list<int> mainChain;
    listBinaryInsertSmallerValues(listOfPairs, mainChain, context);

    return mainChain;
}
