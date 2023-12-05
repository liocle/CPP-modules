/**
 * @file Fixed.cpp
 * @brief Implementation file for the Fixed class.
 */

#include "Fixed.hpp"

/**
 * @brief Default constructor for the Fixed class.
 * Initializes the value to 0.
 */
Fixed::Fixed() : _value(0) {
    std::cout << BLUE << " -- Default constructor called -- " << RESET << std::endl;
}

/**
 * @brief Int constructor for the Fixed class.
 * Converts the provided integer value into a fixed-point representation.
 * @param value The integer value to be converted.
 */
Fixed::Fixed(const int value) : _value(value << _fractionalBits) {
    std::cout << YELLOW << " -- Int constructor called -- " << RESET << std::endl;
}

/**
 * @brief Float constructor for the Fixed class.
 * Converts the provided floating-point value into a fixed-point representation.
 * @param value The floating-point value to be converted.
 */
Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits))) {
    std::cout << RED << " -- Float constructor called -- " << RESET << std::endl;
}

/**
 * @brief Copy constructor for the Fixed class.
 * Copies the value from the source instance to the newly created instance.
 * @param source The source Fixed instance.
 */
Fixed::Fixed(const Fixed &source) : _value(source._value) {
    std::cout << CYAN << " -- Copy constructor called, source's _value set to copied instance's value -- " << RESET << std::endl;
}

/**
 * @brief Destructor for the Fixed class.
 */
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Overloaded assignment operator for the Fixed class.
 * Copies the value from the source instance to the current instance.
 * @param source The source Fixed instance.
 * @return Reference to the current Fixed instance.
 */
Fixed &Fixed::operator=(const Fixed &source) {
    std::cout << MAGENTA << " -- Copy assignment operator called -- " << RESET << std::endl;
    if (this != &source) {
        this->_value = source._value;
    }
    return (*this);
}

/**
 * @brief Get the integer representation of the fixed-point number.
 * @return Integer representation of the fixed-point number.
 */
int Fixed::toInt() const {
    return (_value >> _fractionalBits);
}

/**
 * @brief Get the floating-point representation of the fixed-point number.
 * @return Floating-point representation of the fixed-point number.
 */
float Fixed::toFloat() const {
    return (static_cast<float>(_value) / (1 << _fractionalBits));
}

/**
 * @brief Overloaded << operator for output stream.
 * Outputs the floating-point representation of the Fixed instance.
 * @param out Output stream.
 * @param fixed The Fixed instance to be output.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return (out);
}

