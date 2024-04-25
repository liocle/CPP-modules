#include <iostream>
#include "Colors.h"
#include "MutantStack.hpp"

template <typename T>
void displayMstackInfo(MutantStack<T>& mstack, std::string description) {
    std::cout << CYAN << "-- Mutant stack's info -> " << RESET << description + " " << std::endl;
    if (!mstack.empty()) {
        std::cout << CYAN << "   Top element:\t" << RESET << mstack.top() << std::endl;
        std::cout << CYAN << "   Size:\t" << RESET << mstack.size() << std::endl;
        std::cout << CYAN << "   Content:\t" << RESET;
        for (typename MutantStack<T>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << std::boolalpha << CYAN << "   Empty:\t" << GREEN << mstack.empty() << RESET << std::endl;
    }
}

// Function to test basic stack operations
void testStackOperations() {
    std::cout << YELLOW << "Testing stack operations..." << RESET << std::endl;
    MutantStack<int> stack;
    displayMstackInfo(stack, "Instanciating an empty stack");

    // Push elements
    stack.push(10);
    displayMstackInfo(stack, "push 10 to stack");
    stack.emplace(20);
    displayMstackInfo(stack, "emplace 20 to stack");
    stack.push(30);
    displayMstackInfo(stack, "push 30 to stack");

    // Pop elements and check LIFO order
    stack.pop();
    displayMstackInfo(stack, "pop top value (LIFO)");
    stack.pop();
    displayMstackInfo(stack, "pop top value (LIFO)");

    // Swap content of stack with a new empty stack
    MutantStack<int> anotherStack;
    displayMstackInfo(anotherStack, "Instanciating another empty stack");
    stack.swap(anotherStack);
    displayMstackInfo(anotherStack, "Swapping content from original stack to new stack:");
    displayMstackInfo(stack, "original stack:");
}

// Function to test deque characteristics
void testDequeCharacteristics() {
    MutantStack<int> stack;
    std::cout << YELLOW << "\nTesting deque characteristics via iterators..." << RESET << std::endl;

    // Push elements
    stack.push(1);
    stack.push(2);
    stack.push(3);
    displayMstackInfo(stack, "Initial stack");

    // Use iterator to access elements like a deque
    int i = 1;
    std::cout << "Dereferenced mutant iterator displays: ";
    for (auto it = stack.begin(); it != stack.end(); ++it, ++i) {
        std::cout << *it << " ";
        if (it + 1 == stack.end()) {
            *it = 42;
            std::cout << std::endl;
            displayMstackInfo(stack, "changed last iterated value via iterator");
        }
    }

    // Use reverse iterator
    auto rit = stack.rbegin();
    std::cout << "\n*Mutant reverse iterator points at \"end\":\t" << *rit << std::endl;
    ++rit;
    std::cout << "Incrementing reverse iterator at rbegin() + 1:\t" << *rit << std::endl;
    displayMstackInfo(stack, "stack after being iterated through");

    // Use const_iterator to read and verify contents
    std::cout << "Testing const_iterator: ";
    for (MutantStack<int>::const_iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";  // Should output: 10 20 30
        // *it = 100; // Uncommenting this line should cause a compilation error
    }
    std::cout << std::endl;
}

int main() {
    try {
        testStackOperations();
        testDequeCharacteristics();
    } catch (const std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}
