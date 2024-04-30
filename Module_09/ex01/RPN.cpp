#include "RPN.hpp"
#include <limits>
#include <sstream>
#include <stack>

static bool calculate(char operatorSign, std::stack<double>& stack) {
    if (stack.size() < 2)
        throw RPN::RPNException("Insufficient operands for operation");

    double second = stack.top();
    stack.pop();
    double first = stack.top();
    stack.pop();

    switch (operatorSign) {
        case '+':
            stack.push(first + second);
            break;
        case '-':
            stack.push(first - second);
            break;
        case '*':
            stack.push(first * second);
            break;
        case '/':
            if (second == 0) {
                throw RPN::RPNException("Division by zero");
            }
            stack.push(first / second);
            break;
        default:
            throw RPN::RPNException("Invalid operator");
    }
    return true;
}

int RPN::evaluate(const std::string& input) {
    std::istringstream iss(input);
    std::string token;
    std::stack<double> stack;

    while (iss >> token) {
        if (isdigit(token[0]) && (token.length() == 1)) {
            stack.push(std::stod(token));
        } else if (token.length() == 1 && std::string("+-*/").find(token) != std::string::npos) {
            calculate(token[0], stack);
        } else {
            throw RPN::RPNException("Invalid token or operator");
        }
    }
    if (stack.size() != 1) {
        throw RPN::RPNException("Malformed expression");
    }
    double result = stack.top();
    if (result > static_cast<double>(std::numeric_limits<int>::max()) || result < static_cast<double>(std::numeric_limits<int>::min())) {
        throw RPN::RPNException("Exceed integer range");
    } else {
        return static_cast<int>(result);
    }
}
