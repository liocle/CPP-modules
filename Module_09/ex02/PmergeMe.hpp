// #ifndef PMERGEME_HPP
// #define PMERGEME_HPP

// #include <list>
// #include <vector>

// class PmergeMe {
//    public:
//     static void sortAndDisplayResults(const std::vector<int>& data);
//     static std::list<int> mergeInsertSortList(const std::list<int>& arr);
//     static std::vector<int> mergeInsertSortVector(const std::vector<int>& arr);

//    private:
//     static void mergeInsertPairsLargerValues(std::vector<std::pair<int, int>> &vectorOfPairs, unsigned int left, unsigned int right);
//     static void binaryInsertSmallerValues(std::vector<std::pair<int,int>> &vectorOfPairs, std::vector<int> &mainChain);
// };

// #endif  // PMERGEME_HPP


#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>

class PmergeMe {
   public:
    static std::list<int> mergeInsertSortList(const std::list<int>& arr);
    static std::vector<int> mergeInsertSortVector(const std::vector<int>& arr);

   private:
    static void mergeInsertPairsLargerValues(std::vector<std::pair<int, int>> &vectorOfPairs, unsigned int left, unsigned int right);
    static void binaryInsertSmallerValues(std::vector<std::pair<int, int>>& vectorOfPairs, std::vector<int>& mainChain);
};

#endif  // PMERGEME_HPP

