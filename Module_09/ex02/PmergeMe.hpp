#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include "helper.hpp"


class PmergeMe {
   public:
    template <typename T>
    static T mergeInsertSort(const T& arr, SortContext& context, TimingData& timing);

   private:
    PmergeMe() = delete;
    ~PmergeMe() = delete;
    PmergeMe& operator=(const PmergeMe& source) = delete;
    PmergeMe(const PmergeMe& source) = delete;

    template <typename T>
    static void mergeInsertPairsLargerValues(T& pairs, unsigned int left, unsigned int right, SortContext& context);
    template <typename T, typename K>
    static void binaryInsertSmallerValues(T& pairs, K& mainChain, SortContext& context);
    template <typename T>
    static void binaryInsert(T& mainChain, int value, SortContext& context);
};

#endif  // PMERGEME_HPP
