
#ifndef HELPER_HPP
#define HELPER_HPP

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

#endif // HELPER_HPP
