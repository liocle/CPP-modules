#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>

int RPN::evaluate(const std::string& input) {
    std::istringstream iss(input);
    std::string token;
    std::stack<int> numbers;

    while (iss >> token) {
        if (isdigit(token[0])) {
            numbers.push(std::stoi(token));
        } else {
            if (numbers.size() < 2) {
                std::cerr << "Error\n";
                return -1;
            }
        }
        int second = numbers.top();
        numbers.pop();
        int first = numbers.top();
        numbers.pop();

        switch (token[0]) {
            case '+':
                numbers.push(first + second);
                break;
            case '-':
                numbers.push(first - second);
                break;
            case '*':
                numbers.push(first * second);
                break;
            case '/':
                if (second == 0) {
                    std::cerr << "Error\n";
                    return -1;
                }
                numbers.push(first / second);
                break;
            default:
                std::cerr << "Error\n";
                return -1;
        }
    }
    if (numbers.size() != 1){
        std::cerr << "Error\n";
        return -1;
    }
    return numbers.top();
}
