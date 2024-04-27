#ifndef RPN_HPP
# define RPN_HPP

#include <string>

class RPN {
private:
    RPN(const RPN &other) = delete;
    RPN const& operator=(const RPN &other) = delete;

public:
    RPN() = default;
    ~RPN() = default;
    int evaluate(const std::string& input);
}; 

#endif
