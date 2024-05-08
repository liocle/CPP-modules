#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>

struct SortContext {
    bool hasOddLastElement;
    int oddLastElement;
};

class PmergeMe {
   public:
    static std::list<int> mergeInsertSortList(const std::list<int>& arr);
    static std::vector<int> mergeInsertSortVector(const std::vector<int>& arr);

   private:
    PmergeMe() = delete;
    ~PmergeMe() = delete;
    PmergeMe operator=(const PmergeMe& source) = delete;

    static void vectorMergeInsertPairsLargerValues(std::vector<std::pair<int, int>>& vectorOfPairs, unsigned int left, unsigned int right,
                                                   SortContext context);
    static void vectorBinaryInsertSmallerValues(std::vector<std::pair<int, int>>& vectorOfPairs, std::vector<int>& mainChain,
                                                SortContext context);
    static void vectorBinaryInsertVector(std::vector<int>& mainChain, int value);

    static void listMergeInsertPairsLargerValues(std::list<std::pair<int, int>>& listOfPairs, SortContext context);
    static void listBinaryInsertSmallerValues(std::list<std::pair<int, int>>& listOfPairs, std::list<int>& mainChain, SortContext context);
    static void listBinaryInsertList(std::list<int>& mainChain, int value);
};

#endif  // PMERGEME_HPP
