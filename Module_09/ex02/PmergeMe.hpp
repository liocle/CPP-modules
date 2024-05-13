#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <cstddef>
#include <chrono>


struct SortContext {
    bool hasOddLastElement = false;
    int oddLastElement = 0;
    size_t comparisons = 0;
};

struct TimingData {
  std::chrono::high_resolution_clock::time_point startOverall;
  std::chrono::high_resolution_clock::time_point endOverall;
  std::chrono::high_resolution_clock::time_point startPairingSort;
  std::chrono::high_resolution_clock::time_point endPairingSort;
  std::chrono::high_resolution_clock::time_point startMergeSort;
  std::chrono::high_resolution_clock::time_point endMergeSort;
  std::chrono::high_resolution_clock::time_point startBinaryInsert;
  std::chrono::high_resolution_clock::time_point endBinaryInsert;

  // Function to compute durations in microseconds
  double getOverallDuration() const {
    return std::chrono::duration<double, std::micro>(endOverall - startOverall) .count();
  }
  double getPairingDuration() const {
    return std::chrono::duration<double, std::micro>(endPairingSort - startPairingSort) .count();
  }
  double getMergeSortDuration() const {
    return std::chrono::duration<double, std::micro>(endMergeSort - startMergeSort) .count();
  }
  double getBinaryInsertDuration() const {
    return std::chrono::duration<double, std::micro>(endBinaryInsert - startBinaryInsert) .count();
  }
};

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
