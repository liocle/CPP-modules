#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    /* Preventing instantiation */
    ScalarConverter() = delete; 
    ScalarConverter(ScalarConverter const &source) = delete;
    
    ScalarConverter &operator=(ScalarConverter const &source) = delete;
    ~ScalarConverter();

    static void toChar(double value);
    static void toInt(double value);
    static void toFloat(double value);
    static void toDouble(double value);
    static bool isPrintable(char c);
    static bool isSpecialFloat(double value);
};

#endif // SCALARCONVERTER_HPP

