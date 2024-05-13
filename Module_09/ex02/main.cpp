#include "Colors.h"
#include "PmergeMe.hpp"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <numeric> // For std::accumulate
#include <vector>

template <typename T> bool isSorted(const T &data) {
  return std::is_sorted(data.begin(), data.end());
}

bool validateComparisons(const size_t actualComparisons, const size_t n) {
  const double c = 1; // Adjust based on empirical data or further analysis
  double expectedComparisons = c * n * std::log2(n);
  std::cout << "\nMax expected comp.:\t"
            << (actualComparisons <= expectedComparisons ? GREEN : RED)
            << static_cast<int>(expectedComparisons);
  return actualComparisons <= expectedComparisons;
}

int main(int argc, char *argv[]) {
  for (int i = 0; i < argc; i++) {
    if (argc < 2 || *argv[i] == '\0') {
      std::cout << RED << "Usage: " << argv[0] << " <numbers to be sorted>\n"
                << RESET; // Either was not getting any input or only fed empty
                          // strings
      return 1;
    }
  }

  std::vector<int> inputVector;
  std::deque<int> inputDeque;

  // Parse command line arguments and check for valid integers
  for (int i = 1; i < argc; ++i) {
    char *p;
    long converted = strtol(argv[i], &p, 10);
    if (*p || converted < 0 ||
        converted > static_cast<long>(std::numeric_limits<int>::max())) {
      std::cout
          << RED
          << "Error: Invalid input. Please provide positive integers only.\n";
      return 1;
    }
    inputVector.push_back(static_cast<int>(converted));
    inputDeque.push_back(static_cast<int>(converted));
  }

  std::cout << YELLOW << "Processing " << inputVector.size() << " elements:\t";
  for (size_t number : inputVector) {
    std::cout << number << " ";
  }
  std::cout << RESET << std::endl;

  // Sort using vector
  SortContext contextVector;
  TimingData timingVector;
  timingVector.startOverall = std::chrono::high_resolution_clock::now(); // Main timing start
  auto sortedVector = PmergeMe::mergeInsertSort(inputVector, contextVector, timingVector); // Actual sorting
  timingVector.endOverall = std::chrono::high_resolution_clock::now(); // main timing stops
  std::cout << std::fixed << std::setprecision(2) << YELLOW << std::setw(20)
            << "Vector Overall time:\t" << std::setw(8) << timingVector.getOverallDuration() << " us\t" << RESET << 
  std::setw(20) << "[ Pairing Sort time: " << std::setw(8) << timingVector.getPairingDuration() << " us ]\t" <<
  std::setw(20) << "[ MergeSort time: " << std::setw(8) << timingVector.getMergeSortDuration() << " us ]\t" <<
  std::setw(20) << "[ BinaryInsertion time: " << std::setw(8) << timingVector.getBinaryInsertDuration() << " us ]\n";

  // Sort using deque
  SortContext contextDeque;
  TimingData timingDeque;
  timingDeque.startOverall = std::chrono::high_resolution_clock::now();
  auto sortedDeque = PmergeMe::mergeInsertSort(inputDeque, contextDeque, timingDeque);
  timingDeque.endOverall = std::chrono::high_resolution_clock::now();
  std::cout << std::fixed << std::setprecision(2) << YELLOW << std::setw(20)
            << "Deque Overall time:\t" << std::setw(8) << timingDeque.getOverallDuration() << " us\t" << RESET << 
  std::setw(20) << "[ Pairing Sort time: " << std::setw(8) << timingDeque.getPairingDuration() << " us ]\t" <<
  std::setw(20) << "[ MergeSort time: " << std::setw(8) << timingDeque.getMergeSortDuration() << " us ]\t" <<
  std::setw(20) << "[ BinaryInsertion time: " << std::setw(8 )<< timingDeque.getBinaryInsertDuration() << " us ]\n";

  // ---- Fastest container assessment ----
  std::cout << CYAN << "\n---- Fastest container ----\n" << RESET;
  if (timingVector.getOverallDuration() <= timingDeque.getOverallDuration()) {
    double speedupOverall = (timingDeque.getOverallDuration() / timingVector.getOverallDuration() - 1) * 100;
    double speedupPairing = (timingDeque.getPairingDuration() / timingVector.getPairingDuration() - 1) * 100;
    double speedupMergeSort = (timingDeque.getMergeSortDuration() / timingVector.getMergeSortDuration() - 1) * 100;
    double speedupBinaryInsert = (timingDeque.getBinaryInsertDuration() / timingVector.getBinaryInsertDuration() - 1) * 100;
    std::cout << std::fixed << std::setprecision(2) << GREEN << "Vector fastest by:\t" << std::setw(8)
              << speedupOverall << " % \t" << RESET << std::setw(20) << "[ Pairing: " << std::setw(8) << speedupPairing << " % ]\t"
              << std::setw(20) << "[ MergeSort:" << std::setw(8) << speedupMergeSort
              << " % ]\t" << std::setw(20) << "[ BinaryInsertion: " << std::setw(8) << speedupBinaryInsert << " % ]\n";
  } else {
    double speedupOverall = (timingVector.getOverallDuration() / timingDeque.getOverallDuration() - 1) * 100;
    double speedupPairing = (timingVector.getPairingDuration() / timingDeque.getPairingDuration() - 1) * 100;
    double speedupMergeSort = (timingVector.getMergeSortDuration() / timingDeque.getMergeSortDuration() - 1) * 100;
    double speedupBinaryInsert = (timingVector.getBinaryInsertDuration() / timingDeque.getBinaryInsertDuration() - 1) * 100;
    std::cout << std::fixed << std::setprecision(2) << GREEN << "Deque fastest by:\t" << std::setw(8)
              << speedupOverall << " % \t" << RESET << std::setw(20) << "[ Pairing: " << std::setw(8) << speedupPairing << " % ]\t"
              << std::setw(20) << "[ MergeSort:" << std::setw(8) << speedupMergeSort
              << " % ]\t" << std::setw(20) << "[ BinaryInsertion: " << std::setw(8) << speedupBinaryInsert << " % ]\n";
  }

  // ---- Ford and Johnson comparison, theory vs practice ----
  if (contextVector.comparisons == contextDeque.comparisons) {
    std::cout << CYAN
              << "\n----- Ford and Johnson comparison, theory vs practice ----"
              << RESET;
    bool isValid =
        validateComparisons(contextVector.comparisons, inputVector.size());
    std::cout << (isValid ? " > " : " < ") << contextDeque.comparisons
              << " comparisons were needed to sort this input"
              << "\n"
              << RESET;
  } else {
    std::cout << RED << "\nComparisons between vector and deque do not match\n"
              << RESET;
  }

  // ---- Statistics and integrity checks for Vector ----
  std::cout << CYAN
            << "\n----- Statistics and integrity check for vector ----\n"
            << RESET;
  std::cout << "Input vector size:	" << inputVector.size() << std::endl;
  std::cout << "Sorted vector size:	" << sortedVector.size() << std::endl;

  unsigned long long sumInputVector =
      std::accumulate(inputVector.begin(), inputVector.end(), 0ull,
                      std::plus<unsigned long long>());
  size_t sumSortedVector =
      std::accumulate(sortedVector.begin(), sortedVector.end(), 0ull,
                      std::plus<unsigned long long>());
  std::cout << "Sum of input vector:	" << sumInputVector << std::endl;
  std::cout << "Sum of sorted vector:	" << sumSortedVector << std::endl;
  bool sortedCheckVector = isSorted(sortedVector);
  std::cout << "Is the vector sorted? "
            << (sortedCheckVector ? GREEN "\tYes" : RED "\tNo") << RESET
            << std::endl;

  if (sumInputVector == sumSortedVector &&
      inputVector.size() == sortedVector.size()) {
    std::cout << GREEN << "No numbers were dropped or changed during sorting."
              << RESET << std::endl;
  } else {
    std::cout << RED << "Error: Data mismatch detected!" << RESET << std::endl;
  }

  // Print unsorted / sorted vectors
  size_t maxElementToPrint = 100;
  if (inputDeque.size() < maxElementToPrint) {
    std::cout << "Unsorted vector:\t";
    for (size_t number : inputVector) {
      std::cout << number << " ";
    }
    std::cout << std::endl;
  }
  if (inputVector.size() < maxElementToPrint) {
    std::cout << YELLOW << "Sorted vector:\t\t" << RESET;
    for (int num : sortedVector) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  } else {
    std::cout << YELLOW
              << "Currently limitating printing of unsorted and sorted list to "
              << maxElementToPrint << " elements\n"
              << RESET;
  }

  // ----- Statistics and integrity checks for deque -----
  std::cout << CYAN << "\n----- Statistics and integrity check for deque ----\n"
            << RESET;
  std::cout << "Input deque size:	" << inputDeque.size() << std::endl;
  std::cout << "Sorted deque size:	" << sortedDeque.size() << std::endl;

  size_t sumInputDeque = std::accumulate(inputDeque.begin(), inputDeque.end(),
                                         0ull, std::plus<size_t>());
  size_t sumSortedDeque = std::accumulate(
      sortedDeque.begin(), sortedDeque.end(), 0ull, std::plus<size_t>());
  std::cout << "Sum of input deque:	" << sumInputDeque << std::endl;
  std::cout << "Sum of sorted deque:	" << sumSortedDeque << std::endl;
  bool sortedCheckDeque = isSorted(sortedDeque);
  std::cout << "Is the deque sorted?\t"
            << (sortedCheckDeque ? GREEN "Yes" : RED "No") << std::endl;

  if (sumInputDeque == sumSortedDeque &&
      inputVector.size() == sortedVector.size()) {
    std::cout << GREEN << "No numbers were dropped or changed during sorting."
              << RESET << std::endl;
  } else {
    std::cout << RED << "Error: Data mismatch detected!" << RESET << std::endl;
  }

  // Print unsorted / sorted deques
  if (inputDeque.size() < maxElementToPrint) {
    std::cout << "Unsorted deque:\t\t";
    for (size_t number : inputDeque) {
      std::cout << number << " ";
    }
    std::cout << std::endl;
    if (inputDeque.size() < maxElementToPrint) {
      std::cout << YELLOW << "Sorted deque:\t\t" << RESET;
      for (int num : sortedDeque) {
        std::cout << num << " ";
      }
      std::cout << std::endl;
    }
  } else {
    std::cout
        << YELLOW
        << "Currently limitating printing of unsorted and sorted deque to "
        << maxElementToPrint << " elements\n"
        << RESET;
  }

  return 0;
}
