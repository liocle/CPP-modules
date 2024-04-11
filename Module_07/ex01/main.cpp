#include "iter.h"
#include <iostream>

template <typename T> void printElement(T const &element) {
  std::cout << element << std::endl;
}

template <typename T> void incrementElement(T &element) { element += 42; }

int main(void) {
  {
    int num_array[] = {0, 1, 2, 3, 4};

    std::cout << "-- Original num array:" << std::endl;
    iter(num_array, sizeof(num_array) / sizeof(int), &printElement<int>);
    std::cout << "\n-- Incrementing num array --" << std::endl;
    iter(num_array, sizeof(num_array) / sizeof(int), &incrementElement<int>);
    std::cout << "\n-- Incremented num array:" << std::endl;
    iter(num_array, sizeof(num_array) / sizeof(int), &printElement<int>);
  }

  {
    std::string string_array[] = {"str1", "str2", "str3"};

    std::cout << "-- Original string array:" << std::endl;
    iter(string_array, sizeof(string_array) / sizeof(std::string), &printElement<std::string>);
    std::cout << "\n-- Incrementing string array --" << std::endl;
    iter(string_array, sizeof(string_array) / sizeof(std::string), &incrementElement<std::string>);
    std::cout << "\n-- Incremented string array = Concatenating existing string element with incremented ASCII value:" << std::endl;
    iter(string_array, sizeof(string_array) / sizeof(std::string), &printElement<std::string>);
  }
}
