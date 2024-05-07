#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>

struct SortContext {
    bool hasOddLastElement = false;
    int oddLastElement = 0;
};

class PmergeMe {
   public:
    static std::list<int> mergeInsertSortList(const std::list<int>& arr);
    static std::vector<int> mergeInsertSortVector(const std::vector<int>& arr);

   private:
    static void mergeInsertPairsLargerValues(std::vector<std::pair<int, int>> &vectorOfPairs, unsigned int left, unsigned int right, SortContext context);
    static void binaryInsertSmallerValues(std::vector<std::pair<int, int>>& vectorOfPairs, std::vector<int>& mainChain, SortContext context);
};

#endif  // PMERGEME_HPP

