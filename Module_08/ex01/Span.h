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

    void addNumber(int number);
    unsigned int shortestSpan();
    unsigned int longestSpan() const;

    template<typename Iterator>
    void addRange(Iterator begin, Iterator end);
};

#endif  // SPAN_H
