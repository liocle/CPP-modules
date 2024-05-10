#include "Span.h"
#include <algorithm>
#include <iostream>

// Explicit instantiation for common iterator types
template void Span::addRange<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);
// Add more as needed for each specific iterator needed

Span::Span(unsigned int N) : maxSize_(N){};

Span::~Span(){};

void Span::addNumber(int number) {
    if (numbers_.size() >= maxSize_) {
        throw std::length_error("Span is full");
    }
    numbers_.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (numbers_.size() < 2) {
        throw std::logic_error("Not enough elements for  span calculation");
    }
    std::vector<int> temp = this->numbers_;
    std::sort(temp.begin(), temp.end());
    unsigned int minSpan = UINT_MAX;
    for (unsigned int i = 0; i < temp.size() - 1; ++i ) {
        unsigned int span = temp.at(i + 1) - temp.at(i);
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (numbers_.size() < 2) {
        throw std::logic_error("Not enough elements for  span calculation");
    }
    auto minmaxIteratorsPair = std::minmax_element(numbers_.begin(), numbers_.end());
    return *minmaxIteratorsPair.second - *minmaxIteratorsPair.first;
}

template<typename Iterator> void Span::addRange(Iterator current, Iterator end){
    while (current != end){
        addNumber(*current);
        current++;
    }
}

