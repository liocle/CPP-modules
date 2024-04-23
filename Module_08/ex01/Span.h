#ifndef SPAN_H
#define SPAN_H

#include <vector>

class Span {
   private:
    unsigned int maxSize_;
    std::vector<int> numbers_;

    Span() = delete;
    Span(const Span &other) = delete;
    Span &operator=(const Span &other) = delete;
    
   public:

    Span(unsigned int N);
    ~Span();

    void addNumber(unsigned int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
};

#endif  // SPAN_H
