/**
 * @file ScalarConverter.cpp
 * @brief Contains the implementation of the ScalarConverter class used for converting 
 *        strings to various scalar types in C++.
 */

#include "ScalarConverter.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <regex>
#include "Colors.h"

/**
 * Converts the given string to different scalar types and prints the results.
 * 
 * Handles conversion to char, int, float, and double, including special cases for
 * non-displayable characters and non-finite numbers.
 * 
 * @param literal The string literal to convert and print.
 */
void ScalarConverter::convert(const std::string& literal) {

    if (!isValidNumericInput(literal) && !isCharLiteral(literal)) {
        std::cout << BLUE << "Error: Invalid input. Non-numeric string provided." << RESET << std::endl;
        return;
    }

    // Extreme large/small value check for scientific notation
    if (literal.find('e') != std::string::npos || literal.find('E') != std::string::npos) {
        double testValue = std::stod(literal);
        if (!std::isfinite(testValue)) {  // Checks for +inf, -inf, nan which are results of extreme exponents
            printChar(testValue);
            printInt(testValue);
            printFloat(testValue);
            printDouble(testValue);
            return;
        }
    }

    if (isCharLiteral(literal)) {
        char value = literal[1]; // Assumes the format 'x' where x is the character
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
    } else if (isIntLiteral(literal)) {
        int value = std::stoi(literal);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
    } else if (isFloatLiteral(literal) || isSpecialFloatLiteral(literal)) {
        float value = std::stof(literal);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
    } else {  // Assuming the input is valid and numeric, default to double
        double value = std::stod(literal);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
    }
}

/**
 * Checks if the input string represents a valid numeric input.
 * 
 * @param s The input string to validate.
 * @return True if the string is a valid numeric input, false otherwise.
 */
bool ScalarConverter::isValidNumericInput(const std::string& s) {
    // Regular expression to match a valid numeric input (including scientific notation and special floats)
    static const std::regex validNumericRegex(R"(^[+-]?(?:(?:\d+\.?\d*|\.\d+)(?:[eE][+-]?\d+)?|nanf?|inff?|infinity)$)",
                                              std::regex_constants::icase);
    return std::regex_match(s, validNumericRegex);
}

// Helper methods to detect literal types
bool ScalarConverter::isCharLiteral(const std::string& s) {
    return s.length() == 3 && s.front() == '\'' && s.back() == '\'';
}

bool ScalarConverter::isIntLiteral(const std::string& s) {
    try {
        std::size_t pos;
        (void)std::stoi(s, &pos);
        return pos == s.length();
    } catch (...) {
        return false;
    }
}

bool ScalarConverter::isFloatLiteral(const std::string& s) {
    return s.find('.') != std::string::npos || s.find('f') != std::string::npos;
}

bool ScalarConverter::isSpecialFloatLiteral(const std::string& s) {
    return s == "-inff" || s == "+inff" || s == "nanf";
}

void ScalarConverter::printChar(char value) {
    if (std::isprint(value))
        std::cout << "char:\t'" << value << "'\n";
    else
        std::cout << "char:\tNon displayable\n";
}

void ScalarConverter::printChar(int value) {
    if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && std::isprint(static_cast<char>(value)))
        std::cout << "char:\t'" << static_cast<char>(value) << "'\n";
    else
        std::cout << "char:\timpossible\n";
}

void ScalarConverter::printChar(float value) {
    if (std::isnormal(value) && value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() &&
        std::isprint(static_cast<char>(value)))
        std::cout << "char:\t'" << static_cast<char>(value) << "'\n";
    else
        std::cout << "char:\timpossible\n";
}

void ScalarConverter::printChar(double value) {
    if (std::isnormal(value) && value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() &&
        std::isprint(static_cast<char>(value)))
        std::cout << "char:\t'" << static_cast<char>(value) << "'\n";
    else
        std::cout << "char:\timpossible\n";
}

void ScalarConverter::printInt(int value) {
    std::cout << "int:\t" << value << "\n";
}

void ScalarConverter::printInt(float value) {
    if (!std::isfinite(value)) {  // Ensure not to convert non-finite values (NaN, +/-inf)
        std::cout << "int:\timpossible\n";
        return;
    }
    float rounded = std::round(value);  // Round to nearest integer representation to minimize conversion loss
    if (rounded < static_cast<float>(std::numeric_limits<int>::min()) ||
        rounded > static_cast<float>(std::numeric_limits<int>::max())) {  // Check conversion limites preventing overflow / underflow
        std::cout << "int:\timpossible\n";
    } else {
        std::cout << "int:\t" << static_cast<int>(rounded) << "\n";
    }
}

void ScalarConverter::printInt(double value) {
    if (!std::isfinite(value)) {
        std::cout << "int:\timpossible\n";  // Ensure not to convert non-finite values (NaN, +/-inf)
        return;
    }
    double rounded = std::round(value);  // Round to nearest integer representation to minimize conversion loss
    if (rounded < static_cast<double>(std::numeric_limits<int>::min()) ||
        rounded > static_cast<double>(std::numeric_limits<int>::max())) {  // Check conversion limites preventing overflow / underflow
        std::cout << "int:\timpossible\n";
    } else {
        std::cout << "int:\t" << static_cast<int>(rounded) << "\n";
    }
}

void ScalarConverter::printFloat(int value) {
    std::cout << std::fixed << std::setprecision(1) << "float:\t" << static_cast<float>(value) << "f\n";
}

void ScalarConverter::printFloat(float value) {
    if (value == static_cast<int>(value)) {
        std::cout << std::fixed << std::setprecision(1) << "float:\t" << static_cast<float>(value) << "f\n";
    } else {
        std::cout << "float:\t" << static_cast<float>(value) << "f\n";
    }
}

void ScalarConverter::printFloat(double value) {
    if (value == static_cast<int>(value)) {
        std::cout << std::fixed << std::setprecision(1) << "float:\t" << static_cast<float>(value) << "f\n";
    } else {
        std::cout << "float:\t" << static_cast<float>(value) << "f\n";
    }
}

void ScalarConverter::printDouble(int value) {
    std::cout << std::fixed << std::setprecision(1) << "double:\t" << static_cast<double>(value) << "\n";
}

void ScalarConverter::printDouble(float value) {
    if (value == static_cast<int>(value)) {
        std::cout << std::fixed << std::setprecision(1) << "double:\t" << static_cast<double>(value) << "\n";
    } else {
        std::cout << "double:\t" << static_cast<double>(value) << "\n";
    }
}

void ScalarConverter::printDouble(double value) {
    if (value == static_cast<int>(value)) {
        std::cout << std::fixed << std::setprecision(1) << "double:\t" << static_cast<double>(value) << "\n";
    } else {
        std::cout << "double:\t" << value << "\n";
    }
}
