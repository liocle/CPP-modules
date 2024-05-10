#include <iostream>
#include <numeric>
#include "Span.h"

int main(void) {

    std::cout << "--- Check addNumber with 0 and negative numbers ---" << std::endl;
    try {
        Span sp(3);
        sp.addNumber(-10);
        sp.addNumber(0);
        sp.addNumber(20);
        std::cout << "Added numbers successfully." << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;  // Expected: 10
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;    // Expected: 30
    } catch (const std::exception& e) {
        std::cout << "Added numbers successfully to Span which now contains:" << std::endl;
    }

    std::cout << "\n--- Check adding number in full vector ---" << std::endl;
    try {
        std::vector<int> vec{1,2,3,4,5};
        Span sp(5);
        sp.addRange(vec.begin(), vec.end());  // This should work and fill the Span
        sp.addNumber(30);  // This should throw an exception
    } catch (const std::exception& e) {
        std::cout << "Exception caught on adding to full Span: " << e.what() << std::endl;
    }

    std::cout << "\n--- Check large vector short and long span ---" << std::endl;
    try {
        Span spLarge(10000);
        std::vector<int> largeData(10000);
        std::iota(largeData.begin(), largeData.end(), 1);  // Fill with values 1 to 10000
        spLarge.addRange(largeData.begin(), largeData.end());
        std::cout << "Added 10000 incrementing numbers from 1 to 10000 via addRange successfully." << std::endl;
        std::cout << "Shortest Span of 10000 numbers: " << spLarge.shortestSpan() << std::endl;
        std::cout << "Longest Span of 10000 numbers: " << spLarge.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught on large addRange: " << e.what() << std::endl;
    }

    std::cout << "\n--- Check exception handling when calculating spans with fewer than 2 numbers ---" << std::endl;
    // Test 4: Exception when calculating spans with fewer than 2 numbers
    try {
        Span spSmall(10);
        spSmall.addNumber(1);  // Only one number added
        std::cout << "Shortest Span with insufficient numbers: " << spSmall.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught with insufficient numbers for span:\n" << e.what() << std::endl;
    }

    std::cout << "\n--- Subject test ---" << std::endl;
    try {
        std::vector<int> vec{6,3,17,9,11};
        Span spSubject(5);
        spSubject.addRange(vec.begin(), vec.end());  
        std::cout << "Shortest Span: " << spSubject.shortestSpan() << std::endl;  // Expected: 4
        std::cout << "Longest Span: " << spSubject.longestSpan() << std::endl;    // Expected: 8
    } catch (const std::exception& e) {
        std::cout << "Exception caught during normal operations: " << e.what() << std::endl;
    }

    return 0;
}
