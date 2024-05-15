#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

// Explicit instantiation of the template function
template std::vector<int> PmergeMe::mergeInsertSort<std::vector<int>>(const std::vector<int>&, SortContext&, TimingData&);
template std::deque<int> PmergeMe::mergeInsertSort<std::deque<int>>(const std::deque<int>&, SortContext&, TimingData&);

/**
 * @brief A template structure to define a container type that corresponds to a container of pairs based on the original container's type and allocator.
 *
 * @detail This structure provides a mechanism to transition from any standard container type like `std::vector` or `std::deque`
 * that uses a specific allocator to a similar container type that instead holds elements of type `std::pair<int, int>`.
 * Such templated functions or classes allows operations to be performed on a container that holds pairs, while preserving 
 * the original container type and allocator.
 *
 * @tparam  T The type of elements in the original container.
 */
template <typename Container>
struct MatchingPairContainer;

/**
 * @brief Specialization of MatchingPairContainer for std::vector.
 * @detail Maps a std::vector<T, Alloc> to std::vector<std::pair<int, int>, Alloc::rebind<std::pair<int, int>>::other>.
 * `using type` defines a type alias within the structure.
 * `typename Alloc::template rebind<std::pair<int, int>>::other` uses the allocator's rebind mechanism to change its allocated type from T to std::pair<int, int>
 */
template <typename T, typename Alloc>
struct MatchingPairContainer<std::vector<T, Alloc>> {
    using type = std::vector<std::pair<int, int>, typename Alloc::template rebind<std::pair<int, int>>::other>;
};

/**
 * @brief Specialization of MatchingPairContainer for std::vector.
 * @detail Maps a std::vector<T, Alloc> to std::vector<std::pair<int, int>, Alloc::rebind<std::pair<int, int>>::other>.
 * `using type` defines a type alias within the structure.
 * `typename Alloc::template rebind<std::pair<int, int>>::other` uses the allocator's rebind mechanism to change its allocated type from T to std::pair<int, int>
 */
template <typename T, typename Alloc>
struct MatchingPairContainer<std::deque<T, Alloc>> {
    using type = std::deque<std::pair<int, int>, typename Alloc::template rebind<std::pair<int, int>>::other>;
};

/**
 * @brief Helper function to perform binary insertion for vectors.
 * 
 * @tparam T The type of the container.
 * @param mainChain The container to insert into.
 * @param value The value to insert.
 * @param context The sorting context.
 */
template <typename T>
void PmergeMe::binaryInsert(T& mainChain, int value, SortContext& context) {
    auto it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
    context.comparisons++;
    mainChain.insert(it, std::move(value));  // Use std::move to place value without copying
}

/**
 * @brief Helper function for merging sorted pairs of larger values.
 * 
 * @tparam T The type of the container.
 * @param pairs The container of pairs to merge.
 * @param left The starting index.
 * @param right The ending index.
 * @param context The sorting context.
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
        temp.push_back(std::move(pairs[i]));
        ++i;
    }

    while (j <= right) {
        temp.push_back(std::move(pairs[j]));
        ++j;
    }

    // Move sorted pairs back to the original vector
    for (auto& element : temp) {
        pairs.at(left++) = std::move(element);
    }
}

/**
 * @brief Binary insertion of pairs' second members.
 * 
 * @tparam T The type of the pairs container.
 * @tparam K The type of the main chain container.
 * @param pairs The container of pairs.
 * @param mainChain The main chain container.
 * @param context The sorting context.
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
 * @brief Merge-insertion sorting aka Ford and Johnson algorithm.
 * 
 * @tparam T The type of the container.
 * @param input The input container to sort.
 * @param context The sorting context.
 * @param timing The timing data.
 * @return The sorted container.
 */
template <typename T>
T PmergeMe::mergeInsertSort(const T& input, SortContext& context, TimingData& timing) {
    if (input.size() <= 1) {
        return input;
    }

    size_t i = 0;

    // Step 1: Pair and sort input into a container of T type of pairs of integers.
    timing.startPairingSort = std::chrono::high_resolution_clock::now();  // Pairing: start time
    typename MatchingPairContainer<T>::type pairs;                        // Declare container of type T of pairs as temporary storage
    for (; i < input.size(); i += 2) {                                    // fill pairs with input
        if (i + 1 < input.size()) {
            context.comparisons++;
            if (input[i] >= input[i + 1]) {  // sort first and second members of pairs, larger values populate first member.
                pairs.push_back(std::make_pair(input[i], input[i + 1]));
            } else {
                pairs.push_back(std::make_pair(input[i + 1], input[i]));
            }
        } else {
            context.hasOddLastElement = true;
            context.oddLastElement = input.back();  // if input amount is odd, last input will be handled separately 
        }
    }
    timing.endPairingSort = std::chrono::high_resolution_clock::now();  // Pairing: end time

    // Step 2: Recursive merge sort of sorted first members from container T of pairs of integers.
    timing.startMergeSort = std::chrono::high_resolution_clock::now();  // MergeSort: start time
    unsigned int startIndex = 0;
    unsigned int lastIndex = pairs.size() - 1;
    mergeInsertPairsLargerValues(pairs, startIndex, lastIndex, context);
    timing.endMergeSort = std::chrono::high_resolution_clock::now();  // MergeSort: end time
    
    // Step 3: Binary insertion of unsorted second members of pairs into sorted main chain.
    timing.startBinaryInsert = std::chrono::high_resolution_clock::now();  // BinaryInsertion: start time
    T mainChain;
    binaryInsertSmallerValues(pairs, mainChain, context);
    timing.endBinaryInsert = std::chrono::high_resolution_clock::now();  // BinaryInsertion: end time

    return mainChain;
}
