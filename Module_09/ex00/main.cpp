#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include "BitcoinExchange.hpp"
#include "Colors.h"

auto isNotSpace = [](char c) {
    return !isspace(c);
};

static void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), isNotSpace));
}

static void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), isNotSpace).base(), s.end());
}

static void trim(std::string& s) {
    ltrim(s);
    rtrim(s);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    std::string line, date, valueString;
    int value;
    BitcoinExchange exchange("./data.csv");

    getline(infile, line);
    if (line.find("date | value") != std::string::npos) {
        while (getline(infile, line)) {
            std::istringstream ss(line);
            if (getline(ss, date, '|') && getline(ss, valueString)) {
                trim(date);
                trim(valueString);
                if (!exchange.validateDate(date)) {
                    std::cerr << CYAN << "Error: bad date format => " << RESET << line << std::endl;
                    continue;
                }
                // std::istringstream valueStream(valueString);
                if (exchange.validateValue(valueString) == false) {
                    std::cerr << BLUE << "Error: value out of range." << RESET << std::endl;
                    continue;
                }
                std::istringstream valueStream(valueString);
                valueStream >> value;
                if (!valueStream.eof()) {
                    std::cerr << YELLOW << "Error: bad value format" << RESET << std::endl;
                    continue;
                }
                double rate = exchange.getClosestPrice(date);
                std::cout << date << " => " << value << std::fixed << std::setprecision(2) << " = " << (value * rate) << std::endl;
            } else {
                trim(line);
                if (!line.empty()) {
                    std::cerr << GREEN << "Error: bad input => " << RESET << line << "\n";
                }
            }
        }
    }

    return 0;
}
