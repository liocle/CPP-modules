#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include "helper.hpp"

/**
 * @brief PmergeMe class to perform merge-insert sort using Ford-Johnson algorithm.
 */
class PmergeMe {
   public:
    PmergeMe() = delete;
    ~PmergeMe() = delete;
    PmergeMe& operator=(const PmergeMe& source) = delete;
    PmergeMe(const PmergeMe& source) = delete;

    /**
     * @brief Merge-insertion sorting aka Ford and Johnson algorithm.
     * 
     * @tparam T The type of the container.
     * @param arr The input container to sort.
     * @param context The sorting context.
     * @param timing The timing data.
     * @return The sorted container.
     */
    template <typename T>
    static T mergeInsertSort(const T& arr, SortContext& context, TimingData& timing);

   private:
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
    static void mergeInsertPairsLargerValues(T& pairs, unsigned int left, unsigned int right, SortContext& context);
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
    static void binaryInsertSmallerValues(T& pairs, K& mainChain, SortContext& context);
    /**
     * @brief Helper function to perform binary insertion for containers.
     * 
     * @tparam T The type of the container.
     * @param mainChain The container to insert into.
     * @param value The value to insert.
     * @param context The sorting context.
     */
    template <typename T>
    static void binaryInsert(T& mainChain, int value, SortContext& context);
};

#endif  // PMERGEME_HPP
