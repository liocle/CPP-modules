#include "Colors.h"
#include "BitcoinExchange.hpp"
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    std::ifstream file(filename);
    std::string line, date;
    double price;

    while (getline(file, line)) {
        std::istringstream ss(line);
        if (getline(ss, date, ',') && ss >> price) {
            priceData_[date] = price;
        }
    }
}

double BitcoinExchange::getClosestPrice(const std::string& date) {
    auto it = priceData_.lower_bound(date); // Returns an iterator pointing to the first elemenet that is not less than (i.e. >= to) key.
    if (it != priceData_.begin() && it->first != date) {
        --it; // if key != date, iterate to previous key value
    }
    return it->second;
}

bool BitcoinExchange::validateDate(const std::string& date) {
    std::tm tm = {};  // Structure holding calendar date broken doown into its components
    std::istringstream ss(date);
    // Attempt to parse std::tm strucutre using std::get_time. If parsing fails (incorrect format or invalid date), it returns false
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) {
        return false;
    }

    std::time_t time = std::mktime(&tm);
    if (time == -1) {
        return false;
    }

    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tm);
    return date == buffer;
}

bool BitcoinExchange::validateValue(const std::string& valueString) {
    float value = 0;
    std::istringstream ss(valueString);


    if (!(ss >> value)){
        return false;
    }

    char extra;
    if (ss >> extra) {
        std::cout << RED << "here" << RESET << std::endl;
        return false; // Extra characters present after the number
    }

    if (value < 0.0f || value > 1000.0f) {
        return false; 
    }
    return true;
}
