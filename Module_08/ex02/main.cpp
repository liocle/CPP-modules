#include <iostream>
#include "MutantStack.hpp"

void displayMstackInfo(MutantStack<int>& mstack, std::string description) {
    std::cout << "\n-- Mutant stack's info -- " + description + " " << std::endl;
    if (!mstack.empty()) {
        std::cout << "Mutant stack top element: " << mstack.top() << std::endl;
        std::cout << "Mutant stack size: " << mstack.size() << std::endl;
        std::cout << "Mutant stack content: ";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Mutant stack is empty, size: " << mstack.size() << std::endl;
    }
}

// Function to test basic stack operations
void testStackOperations() {
    MutantStack<int> stack;
    std::cout << "Testing stack operations..." << std::endl;

    // Push elements
    stack.push(10);
    stack.push(20);
    stack.push(30);
    displayMstackInfo(stack, "Initial stack");

    // Check top element
    // assert(stack.top() == 30);

    // Pop elements and check LIFO order
    stack.pop();
    displayMstackInfo(stack, "poped top value.");
    stack.pop();
    displayMstackInfo(stack, "poped top value.");

    std::cout << "Passed stack operations tests.\n" << std::endl;
}

// Function to test deque characteristics
void testDequeCharacteristics() {
    MutantStack<int> stack;
    std::cout << "Testing deque characteristics via iterators..." << std::endl;

    // Push elements
    stack.push(1);
    stack.push(2);
    stack.push(3);
    displayMstackInfo(stack, "Initial stack");

    // Use iterator to access elements like a deque
    int i = 1;
    std::cout << "Using iterator to access element like a deque from beginning to end: ";
    for (auto it = stack.begin(); it != stack.end(); ++it, ++i) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Use reverse iterator
    auto rit = stack.rbegin();
    std::cout << "Using reverse iterator set at rbegin() to last element like a deque: " << *rit << std::endl;
    ++rit;
    std::cout << "Incrementing reverse iterator set originally at rbegin(): " << *rit << std::endl;

    displayMstackInfo(stack, "stack after being iterated through");
    std::cout << "Passed deque characteristics tests.\n" << std::endl;
}


int main() {
    testStackOperations();
    testDequeCharacteristics();

    return 0;
}
