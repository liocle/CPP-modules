#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

class ScalarConverter {
   public:
    static void convert(const std::string& literal);

   private:
    /* Preventing instantiation */
    ScalarConverter() = delete;
    ScalarConverter(ScalarConverter const& source) = delete;

    ScalarConverter& operator=(ScalarConverter const& source) = delete;
    ~ScalarConverter();

    static bool isCharLiteral(const std::string& s);
    static bool isIntLiteral(const std::string& s);
    static bool isFloatLiteral(const std::string& s);
    static bool isSpecialFloatLiteral(const std::string& s);
    static bool isDoubleLiteral(const std::string& s);
    static bool isValidNumericInput(const std::string& s);

    static void printChar(const char value);
    static void printChar(const int value);
    static void printChar(const float value);
    static void printChar(const double value);
    
    static void printInt(const int value);
    static void printInt(const float value);
    static void printInt(const double value);

    static void printFloat(const int value);
    static void printFloat(const float value);
    static void printFloat(const double value);

    static void printDouble(const int value);
    static void printDouble(const float value);
    static void printDouble(const double value);
};

#endif  // SCALARCONVERTER_H
