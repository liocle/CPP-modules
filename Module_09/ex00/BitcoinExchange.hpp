#pragma once

#include <limits>
#include <map>

class BitcoinExchange {
   private:
    std::map<std::string, double> priceData_;
    BitcoinExchange() = delete;
    BitcoinExchange(const BitcoinExchange &source) = delete;
    BitcoinExchange operator=(const BitcoinExchange &source) = delete;
    
   public:
    BitcoinExchange(const std::string &filename);
    ~BitcoinExchange() = default;

    double getClosestPrice(const std::string &date);
    bool validateDate(const std::string &date);
    bool validateValue(const std::string &Value);
};


