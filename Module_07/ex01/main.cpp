#include "iter.h"
#include <iostream>

template <typename T> void printElement(T const &element) {
  std::cout << element << std::endl;
}

template <typename T> void incrementElement(T &element) { element += 42; }

int main(void) {
  {
    int num_array[] = {0, 1, 2, 3, 4};

    std::cout << "[Type 1]: Original num array:" << std::endl;
    iter(num_array, sizeof(num_array) / sizeof(int), &printElement<int>);
    std::cout << "\n-- Incrementing and printing resulting num array --" << std::endl;
    iter(num_array, sizeof(num_array) / sizeof(int), &incrementElement<int>);
    iter(num_array, sizeof(num_array) / sizeof(int), &printElement<int>);
  }

  {
    std::string string_array[] = {"str1", "str2", "str3"};

    std::cout << "\n\n[Type 2]: Original string array:" << std::endl;
    iter(string_array, sizeof(string_array) / sizeof(std::string), &printElement<std::string>);
    std::cout << "\n-- Incrementing string array = Concatenates existing string element with new char equivalent of ASCII value:" << std::endl;
    iter(string_array, sizeof(string_array) / sizeof(std::string), &incrementElement<std::string>);
    iter(string_array, sizeof(string_array) / sizeof(std::string), &printElement<std::string>);
  }
}
