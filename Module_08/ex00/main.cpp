#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

template <typename T>
void findInContainer(T& container, int value) {

    try {
        typename T::iterator it = easyfind(container, value);
        std::cout << "Found: " << *it << " at slot " << std::distance(container.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

int main(void) {
    std::array<int, 5> myArray{10, 20, 30, 40, 50};
    std::vector<int> myVector{10, 20, 30, 40, 50};
    std::list<int> myList{10, 20, 30, 40, 50};
    std::deque<int> myDeque{10, 20, 30, 40, 50};

    std::vector<int> emptyVector{};
    std::array<int, 0> emptyArray{};
    std::vector<int> repeatedValues{10, 10, 20, 30, 40, 50};

    std::cout << "Seek exisiting value 20 in array" << std::endl;
    findInContainer(myArray, 20);

    std::cout << "\nSeek exisiting value 20 in vector" << std::endl;
    findInContainer(myVector, 20);

    std::cout << "\nSeek exisiting value 20 in myList" << std::endl;
    findInContainer(myList, 20);

    std::cout << "\nSeek exisiting value 20 in myDeque" << std::endl;
    findInContainer(myDeque, 20);

    std::cout << "\nSeek non exisiting value 20 in emptyVector" << std::endl;
    findInContainer(emptyVector, 20);

    std::cout << "\nSeek non exisiting value 20 in emptyArray" << std::endl;
    findInContainer(emptyArray, 20);

    std::cout << "\nSeek exisiting multiple value 10 in vector" << std::endl;
    findInContainer(myVector, 10);

    return 0;
}
