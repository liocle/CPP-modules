#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

// Helper function to perform binary insertion for vectors
template <typename T>
void binaryInsertVector(T &container, typename T::value_type value) {
  auto it = std::lower_bound(container.begin(), container.end(), value);
  container.insert(it, value);
}

// Helper function to perform binary insertion for lists
template <typename T>
void binaryInsertList(T &container, typename T::value_type value) {
  auto it = std::find_if(
      container.begin(), container.end(),
      [&](const typename T::value_type &elem) { return value < elem; });
  container.insert(it, value);
}

// Merge-insertion sort for vector
std::vector<int> PmergeMe::mergeInsertSortVector(const std::vector<int> &input) {
  if (input.size() <= 1) {
    return input;
  }

  std::vector<std::pair<int, int>> vectorOfPairs;
  for (size_t i = 0; i < input.size(); i += 2) {
    if (i + 1 < input.size()) {
      vectorOfPairs.push_back(std::make_pair(input[i], input[i + 1]));
    } else {
      vectorOfPairs.back().first = input[i];
    }
  }
      
  sortInsidePairs();

  mergePairsLargerValues();

  binaryInsertSmallerValues();

  std::vector<int> sortedAList = mergeInsertSortVector(aList); // Recursive sort
  for (const auto &b : bList) {
    binaryInsertVector(sortedAList, b);
  }

  return sortedAList;
}

// Merge-insertion sort for list
std::list<int> PmergeMe::mergeInsertSortList(const std::list<int> &arr) {
  if (arr.size() <= 1) {
    return arr;
  }

  std::list<int> aList, bList;
  auto it = arr.begin();
  while (it != arr.end()) {
    auto next = std::next(it);
    if (next != arr.end()) {
      if (*it < *next) {
        bList.push_back(*it);
        aList.push_back(*next);
        ++next;
      } else {
        bList.push_back(*next);
        aList.push_back(*it);
      }
      ++it; // Move to the next pair
    } else {
      aList.push_back(*it); // Odd element
    }
    it = next;
  }

  std::list<int> sortedAList = mergeInsertSortList(aList); // Recursive sort
  for (const auto &b : bList) {
    binaryInsertList(sortedAList, b);
  }
  std::cout << "MergeInsertSortList: test " << std::endl;

  return sortedAList;
}
