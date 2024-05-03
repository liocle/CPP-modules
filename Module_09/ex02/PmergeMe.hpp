#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>

class PmergeMe {
public:
    static void sortAndDisplayResults(const std::vector<int>& data);
    static std::list<int> mergeInsertSortList(const std::list<int> &arr);
    static std::vector<int> mergeInsertSortVector(const std::vector<int> &arr);

private:

    template<typename Container>
    static void pairAndSort(const Container& arr, Container& aList, Container& bList);
    template<typename Container>
    static void binaryInsert(Container& aList, typename Container::value_type value);
};

#endif // PMERGEME_HPP


