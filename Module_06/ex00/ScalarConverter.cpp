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

    // Check for input validity and returns if check fails
    if (!isValidNumericInput(literal) && !isCharLiteral(literal)) {
        std::cout << RED << "Error: Invalid input. Non-numeric string provided." << RESET << std::endl;
        return;
    }

    // Check for scientific notation
    if (literal.find('e') != std::string::npos || literal.find('E') != std::string::npos) {
        double testValue;
        try {
            testValue = std::stod(literal);
        } catch (...) {
            std::cout << RED << " -> out of range" << std::endl;
            std::cout << "char:\timpossible\n";
            std::cout << "int:\timpossible\n";
            std::cout << "float:\timpossible\n";
            std::cout << "double:\timpossible\n";
            std::cout << RESET << std::endl;
            return;
        }

        if (!std::isfinite(testValue)) {  // Checks for +inf, -inf, nan which are results of extreme exponents
            std::cout << GREEN << " -> char" << std::endl;
            printChar(testValue);
            printInt(testValue);
            printFloat(testValue);
            printDouble(testValue);
            std::cout << RESET;
            return;
        }
    }

    if (isCharLiteral(literal)) {
        char value = literal[1];  // Assumes the format 'x' where x is the character
        std::cout << MAGENTA << " -> char" << std::endl;
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        std::cout << RESET;
    } else if (isIntLiteral(literal)) {
        std::cout << BLUE << " -> int" << std::endl;
        int value = std::stoi(literal);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        std::cout << RESET;
    } else if (isFloatLiteral(literal) || isSpecialFloatLiteral(literal)) {
        try {
            float value = std::stof(literal);
            std::cout << LIGHT_BLUE << " -> float" << std::endl;
            printChar(value);
            printInt(value);
            printFloat(value);
            printDouble(value);
        } catch (...) {
            double value;
            try {
                value = std::stod(literal);
                std::cout << LIGHT_YELLOW << " -> double, caught from stof" << std::endl;
                printChar(value);
                printInt(value);
                printFloat(value);
                printDouble(value);
            } catch (...) {
                std::cout << RED << " -> out of range" << std::endl;
                std::cout << "char:\timpossible\n";
                std::cout << "int:\timpossible\n";
                std::cout << "float:\timpossible\n";
                std::cout << "double:\timpossible\n";
                std::cout << RESET << std::endl;
                return;
            }
        }
        std::cout << RESET;
    } else {  // Assuming the input is valid and numeric, default to double
        double value;
        try {
            value = std::stod(literal);
            std::cout << LIGHT_YELLOW << " -> double" << std::endl;
            printChar(value);
            printInt(value);
            printFloat(value);
            printDouble(value);
        } catch (...) {
            std::cout << RED << " -> out of range" << std::endl;
            std::cout << "char:\timpossible\n";
            std::cout << "int:\timpossible\n";
            std::cout << "float:\timpossible\n";
            std::cout << "double:\timpossible\n";
            std::cout << RESET << std::endl;
            return;
        }
    }
    std::cout << RESET;
}

/**
 * @brief Checks if the input string represents a valid numeric input.
 *
 * @detail Validate numeric inputs, including integers, floating-point numbers, numbers 
 * in scientific notation, and special values like "nan", "inf", and "infinity" case insensitively.
 * Refer to Regex.md for details about how this regex function works.
 * This funciton encapsulates validdNumericRegex() inside isValidNumericInput().
 * 
 * @param s The input string to validate.
 * @return True if the string is a valid numeric input, false otherwise.
 */
bool ScalarConverter::isValidNumericInput(const std::string& s) {
    // Regular expression to match a valid numeric input (including scientific notation and special floats)
    static const std::regex validNumericRegex(R"(^[+-]?(?:(?:\d+\.?\d*|\.\d+)(?:[eE][+-]?\d+)?|nanf?|inff?|infinity)$)",
                                              std::regex_constants::icase);  // flag allow case insensitive matches
    return std::regex_match(s, validNumericRegex);                           // filters input string
}

/**
 * Detect literal type
 */
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
    if (s.find('.') != std::string::npos || s.find('f') != std::string::npos)
        return true;
    else
        return false;
}

bool ScalarConverter::isSpecialFloatLiteral(const std::string& s) {
    return s == "-inff" || s == "+inff" || s == "nanf";
}

/**
 * Print Char helper function...
 *
 * directly from char or converted from int, float and double data types.
 */
void ScalarConverter::printChar(const char value) {
    if (std::isprint(value))
        std::cout << "char:\t'" << value << "'\n";
    else
        std::cout << "char:\tNon displayable\n";
}

void ScalarConverter::printChar(const int value) {
    if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && std::isprint(static_cast<char>(value)))
        std::cout << "char:\t'" << static_cast<char>(value) << "'\n";
    else
        std::cout << "char:\timpossible\n";
}

void ScalarConverter::printChar(const float value) {
    if (std::isnormal(value) && value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() &&
        std::isprint(static_cast<char>(value)))
        std::cout << "char:\t'" << static_cast<char>(value) << "'\n";
    else
        std::cout << "char:\timpossible\n";
}

void ScalarConverter::printChar(const double value) {
    if (std::isnormal(value) && value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() &&
        std::isprint(static_cast<char>(value)))
        std::cout << "char:\t'" << static_cast<char>(value) << "'\n";
    else
        std::cout << "char:\timpossible\n";
}

/**
 * Print Int helper function...
 * 
 * directly from int or converted from float and double data types.
 */
void ScalarConverter::printInt(const int value) {
    std::cout << "int:\t" << value << "\n";
}

void ScalarConverter::printInt(const float value) {
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

void ScalarConverter::printInt(const double value) {
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

/**
 * Print Float helper function...
 * 
 * directly from float or converted from int and double data types.
 */
void ScalarConverter::printFloat(const int value) {
    std::cout << std::fixed << std::setprecision(1) << "float:\t" << static_cast<float>(value) << "f\n";
}

void ScalarConverter::printFloat(const float value) {
    if (value == static_cast<int>(value)) {
        std::cout << std::fixed << std::setprecision(1) << "float:\t" << static_cast<float>(value) << "f\n";
    } else {
        std::cout << "float:\t" << static_cast<float>(value) << "f\n";
    }
}

void ScalarConverter::printFloat(const double value) {
    if (value == static_cast<int>(value)) {
        std::cout << std::fixed << std::setprecision(1) << "float:\t" << static_cast<float>(value) << "f\n";
    } else {
        std::cout << "float:\t" << static_cast<float>(value) << "f\n";
    }
}

/**
 * Print Double helper function...
 * 
 * directly from double or converted from int and float data types.
 */
void ScalarConverter::printDouble(const int value) {
    std::cout << std::fixed << std::setprecision(1) << "double:\t" << static_cast<double>(value) << "\n";
}

void ScalarConverter::printDouble(const float value) {
    if (value == static_cast<int>(value)) {
        std::cout << std::fixed << std::setprecision(1) << "double:\t" << static_cast<double>(value) << "\n";
    } else {
        std::cout << "double:\t" << static_cast<double>(value) << "\n";
    }
}

void ScalarConverter::printDouble(const double value) {
    if (value == static_cast<int>(value)) {
        std::cout << std::fixed << std::setprecision(1) << "double:\t" << static_cast<double>(value) << "\n";
    } else {
        std::cout << "double:\t" << value << "\n";
    }
}
