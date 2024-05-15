
#ifndef HELPER_HPP
#define HELPER_HPP

#include <chrono>
#include <cstddef>

/**
 * @brief Structure to hold context information during sorting.
 */
struct SortContext {
    bool hasOddLastElement = false;  // Flag to indicate if there is an odd last element.
    int oddLastElement = 0;          // Value of the odd last element.
    size_t comparisons = 0;          // Number of comparisons made during sorting.
};

/**
 * @brief Structure to hold timing data for various stages of the sorting process.
 */
struct TimingData {
    std::chrono::high_resolution_clock::time_point startOverall;
    std::chrono::high_resolution_clock::time_point endOverall;
    std::chrono::high_resolution_clock::time_point startPairingSort;
    std::chrono::high_resolution_clock::time_point endPairingSort;
    std::chrono::high_resolution_clock::time_point startMergeSort;
    std::chrono::high_resolution_clock::time_point endMergeSort;
    std::chrono::high_resolution_clock::time_point startBinaryInsert;
    std::chrono::high_resolution_clock::time_point endBinaryInsert;

    /**
     * @brief Function to compute overall duration in microseconds.
     * @return Overall duration in microseconds.
     */
    double getOverallDuration() const { return std::chrono::duration<double, std::micro>(endOverall - startOverall).count(); }

    /**
     * @brief Function to compute pairing sort duration in microseconds.
     * @return Pairing sort duration in microseconds.
     */
    double getPairingDuration() const { return std::chrono::duration<double, std::micro>(endPairingSort - startPairingSort).count(); }

    /**
     * @brief Function to compute merge sort duration in microseconds.
     * @return Merge sort duration in microseconds.
     */
    double getMergeSortDuration() const { return std::chrono::duration<double, std::micro>(endMergeSort - startMergeSort).count(); }

    /**
     * @brief Function to compute binary insert duration in microseconds.
     * @return Binary insert duration in microseconds.
     */
    double getBinaryInsertDuration() const {
        return std::chrono::duration<double, std::micro>(endBinaryInsert - startBinaryInsert).count();
    }
};

#endif  // HELPER_HPP
