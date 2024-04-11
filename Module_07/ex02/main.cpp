#include "Array.h"
#include <iostream>

#define SIZE 5

template <typename T> void printArray(Array<T> &arr) {
  std::cout << "[ ";
  for (unsigned int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

int main(void) {
  Array<int> numbers(SIZE);

  // Check that array works as a normal array
  int *mirror = new int[SIZE];
  srand(time(NULL));
  for (unsigned int i = 0; i < SIZE; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  for (unsigned int i = 0; i < SIZE; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  delete[] mirror;

  std::cout << "Original array:" << std::endl;
  printArray(numbers);
  
  // Check index exceptions
  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[numbers.size()] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  
  // Edit the array using subscript operator
  for (unsigned int i = 0; i < numbers.size(); i++) {
    numbers[i] = i;
  }
  std::cout << "\nOriginal array after rewriting:" << std::endl;
  printArray(numbers);

  Array<int> emptyArr(0);
  std::cout << "\nEmpty array:" << std::endl;
  printArray(emptyArr);

  // Check assignment and copy constructor
  {
    Array<int> tmp = numbers;
    std::cout << "\nAssignment test:" << std::endl;
    printArray(tmp);
    Array<int> test(numbers);
    std::cout << "\nCopy constructor test:" << std::endl;
    printArray(test);
    emptyArr = test;
    std::cout << "\nEmpty array after assignment:" << std::endl;
    printArray(emptyArr);
  }
  return 0;
}
