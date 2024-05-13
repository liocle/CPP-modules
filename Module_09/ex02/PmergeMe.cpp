#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

template std::vector<int> PmergeMe::mergeInsertSort<std::vector<int>>(const std::vector<int>&, SortContext&, TimingData&);
template std::deque<int> PmergeMe::mergeInsertSort<std::deque<int>>(const std::deque<int>&, SortContext&, TimingData&);

/**
 * @brief Helper function to perform binary insertion for vectors
 */
template <typename T>
void PmergeMe::binaryInsert(T& mainChain, int value, SortContext& context) {
    auto it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
    context.comparisons++;
    mainChain.insert(it, std::move(value)); // Use std::move to place value without copying
}

/**
 * @brief  Helper function for merging sorted pairs of larger values
 *
 */
template <typename T>
void PmergeMe::mergeInsertPairsLargerValues(T& pairs, unsigned int left, unsigned int right, SortContext& context) {
    if (left >= right) {
        return;
    }

    // Find the middle point
    unsigned int mid = (left + right) / 2;

    // Recursively divide and sort both halves
    mergeInsertPairsLargerValues(pairs, left, mid, context);
    mergeInsertPairsLargerValues(pairs, mid + 1, right, context);

    // Merging sorted pairs by their larger values
    T temp;
    unsigned int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        context.comparisons++;
        if (pairs[i].first <= pairs[j].first) {
            temp.push_back(pairs[i]);
            ++i;
        } else {
            temp.push_back(pairs[j]);
            ++j;
        }
    }

    // Append remaining elements from either half
    while (i <= mid) {
        temp.push_back(pairs[i]);
        ++i;
    }

    while (j <= right) {
        temp.push_back(pairs[j]);
        ++j;
    }

    // Move sorted pairs back to the original vector
    for (unsigned int k = 0; k < temp.size(); ++k) {
        pairs[left + k] = temp[k];
    }
}

/**
 * @brief binary insertion of pairs' second member
 *
 */
template <typename T, typename K>
void PmergeMe::binaryInsertSmallerValues(T& pairs, K& mainChain, SortContext& context) {
    size_t j = 0;

    mainChain.push_back(pairs[j].second);  // second member of first pair is known to be smaller than first member
    mainChain.push_back(pairs[j].first);
    j++;  // first pair hanlded

    // Ford and Johnson requires sorted larger pair valued to fill main chain
    for (size_t i = j; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
    }

    // Ford and Johnson generalization for first half of list of Demuth five element sorting
    for (; j <= (pairs.size() - 1) / 2;
         ++j) {  // until first half of amount of pairs, handle pairs[j+1].second, then vectorofPairs[j].second.
        if (j + 1 <= (pairs.size() - 1) / 2) {
            binaryInsert(mainChain, pairs[j + 1].second, context);
            binaryInsert(mainChain, pairs[j].second, context);
            j++;
        } else {
            binaryInsert(mainChain, pairs[j].second, context);
        }
    }

    // Ford and Johnson require after reaching half of the pairs to insert last unpaired value if existing
    if (context.hasOddLastElement == true) {
        binaryInsert(mainChain, context.oddLastElement, context);
    }

    // Ford and Johnson insert each paired second member from last pair back to middle pair
    for (size_t k = pairs.size() - 1; k > (pairs.size() - 1) / 2; --k) {
        binaryInsert(mainChain, pairs[k].second, context);
    }
}

/**
  * @brief  Merge-insertion sort for vector
  *
  */
template <typename T>
T PmergeMe::mergeInsertSort(const T& input, SortContext& context, TimingData& timing) {
    if (input.size() <= 1) {
        return input;
    }

    size_t i = 0;

    std::vector<std::pair<int, int>> pairs;  // Declare vector of pairs
    timing.startPairingSort = std::chrono::high_resolution_clock::now();
    for (; i < input.size(); i += 2) {       // fill pairs with input
        if (i + 1 < input.size()) {
            context.comparisons++;
            if (input[i] >= input[i + 1]) {  // sort first and second members of pairs, larger values populate first member.
                pairs.push_back(std::make_pair(input[i], input[i + 1]));
            } else {
                pairs.push_back(std::make_pair(input[i + 1], input[i]));
            }
        } else {
            context.hasOddLastElement = true;
            context.oddLastElement = input.back();  // if input amount is odd, last input will be handled specifically, as per Ford Johnson
        }
    }
    timing.endPairingSort = std::chrono::high_resolution_clock::now();

    unsigned int startIndex = 0;
    unsigned int lastIndex = pairs.size() - 1;
    timing.startMergeSort = std::chrono::high_resolution_clock::now();
    mergeInsertPairsLargerValues(pairs, startIndex, lastIndex, context);
    timing.endMergeSort = std::chrono::high_resolution_clock::now();

    T mainChain;
    timing.startBinaryInsert = std::chrono::high_resolution_clock::now();
    binaryInsertSmallerValues(pairs, mainChain, context);
    timing.endBinaryInsert = std::chrono::high_resolution_clock::now();

    return mainChain;
}
