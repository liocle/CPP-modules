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
    static bool isValidNumericInput(const std::string& s);

    static void printChar(char value);
    static void printChar(int value);
    static void printChar(float value);
    static void printChar(double value);
    
    static void printInt(int value);
    static void printInt(float value);
    static void printInt(double value);

    static void printFloat(int value);
    static void printFloat(float value);
    static void printFloat(double value);

    static void printDouble(int value);
    static void printDouble(float value);
    static void printDouble(double value);
};

#endif  // SCALARCONVERTER_H
