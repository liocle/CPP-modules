#pragma once

#include <map>

/**
 * @brief    BitcoinExchange class to manage Bitcoin price data and queries.
 * @detail   - The use of =delete explicitly prevents generation and usage of certain functions.
 *           - Provides clearer error messages when accidental use of those functions occurs.
 *           - More modern than simply having them as private (they would be generated but unusable).
 *           - Saves compile time and space.
 */
class BitcoinExchange {
   private:
    std::map<std::string, double> priceData_;  // Container to store price data indexed by date.

   public:
    /**
     * @brief Constructor that loads price data from a CSV file.
     * 
     * @param filename The name of the CSV file containing the price data.
     */
    BitcoinExchange(const std::string& filename);
    ~BitcoinExchange() = default;

    // Deleted functions to prevent undesired operations
    BitcoinExchange() = delete;
    BitcoinExchange(const BitcoinExchange& source) = delete;
    BitcoinExchange operator=(const BitcoinExchange& source) = delete;

    /**
     * @brief Gets the closest price to the given date.
     * 
     * @param date The date for which to get the closest price.
     * @return The closest price to the given date.
     */
    double getClosestPrice(const std::string& date);
    /**
     * @brief Validates if the provided date is in the correct format (YYYY-MM-DD).
     * 
     * @param date The date to validate.
     * @return True if the date is valid, false otherwise.
     */
    bool validateDate(const std::string& date);
    /**
     * @brief Validates if the provided value is within the acceptable range (0 to 1000).
     * 
     * @param valueString The value to validate as a string.
     * @return True if the value is valid, false otherwise.
     */
    bool validateValue(const std::string& Value);
};
