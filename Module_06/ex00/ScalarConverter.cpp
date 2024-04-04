#include "ScalarConverter.h"
#include <iostream>
#include <sstream>
#include <limits>

void ScalarConverter::convert(const std::string& literal) {
    double value;
    std::istringstream iss(literal);
    if (!(iss >> value)) {
        std::cerr << "Error: Invalid input" << std::endl;
        return;
    }

    toChar(value);
    toInt(value);
    toFloat(value);
    toDouble(value);
}

void ScalarConverter::toChar(double value) {
    char c = static_cast<char>(value);
    if (isPrintable(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable or impossible" << std::endl;
}

void ScalarConverter::toInt(double value) {
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::toFloat(double value) {
    if (isSpecialFloat(value))
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::toDouble(double value) {
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

bool ScalarConverter::isPrintable(char c) {
    return c >= 32 && c <= 126;
}

bool ScalarConverter::isSpecialFloat(double value) {
    return std::isinf(value) || std::isnan(value);
}

