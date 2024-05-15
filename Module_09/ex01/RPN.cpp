#include "RPN.hpp"
#include <limits>
#include <sstream>
#include <stack>

/**
 * @brief Performs a calculation with the given operator and stack.
 * 
 * @param operatorSign The operator to perform (+, -, *, /).
 * @param stack The stack of operands.
 * @throws RPNException if there are insufficient operands or if an invalid operator is encountered.
 */
static void calculate(char operatorSign, std::stack<double>& stack) {
    if (stack.size() < 2)
        throw RPN::RPNException("Insufficient operands for operation");

    double second = stack.top();  // The second operand
    stack.pop();
    double first = stack.top();  // The first operand
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
}

/**
 * @brief Evaluates a given RPN expression.
 * 
 * @param input The RPN expression as a string.
 * @return The result of the evaluation as an integer.
 * @throws RPNException if the expression is invalid or an error occurs during evaluation.
 */
int RPN::evaluate(const std::string& input) {
    std::istringstream iss(input);
    std::string token;
    std::stack<double> stack;

    // Process each token in the input
    while (iss >> token) {
        if (isdigit(token[0]) && (token.length() == 1)) {
            // Push single-digit operand onto the stack
            stack.push(token[0] - '0');
        } else if (token.length() == 1 && std::string("+-*/").find(token) != std::string::npos) {
            // Perform calculation with the operator
            calculate(token[0], stack);
        } else {
            // Invalid token or operator
            throw RPN::RPNException("Invalid token or operator");
        }
    }
    // After processing all tokens, there should be exactly one element, i.e. the result, in the stack
    if (stack.size() != 1) {
        throw RPN::RPNException("Malformed expression");
    }
    double result = stack.top();
    // Check for integer overflow/underflow
    if (result > static_cast<double>(std::numeric_limits<int>::max()) || result < static_cast<double>(std::numeric_limits<int>::min())) {
        throw RPN::RPNException("Exceed integer range");
    }

    return static_cast<int>(result);
}
