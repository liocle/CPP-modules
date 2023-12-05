#include "Fixed.hpp"

/**
 * @brief Default constructor.
 * Initializes the value to 0.
 */
Fixed::Fixed() : _value(0) {
    std::cout << BLUE << " -- Default constructor called, initialized _value to 0 -- " << RESET << std::endl;
}

/**
 * @brief Copy constructor.
 * Initializes the value with the source object's value.
 *
 * @param source The source object to copy.
 */
Fixed::Fixed(const Fixed &source) : _value(source._value) {
    std::cout << CYAN << " -- Copy constructor called, source's _value set to copied instance's value -- " << RESET << std::endl;
}

/**
 * @brief Destructor.
 */
Fixed::~Fixed() {
    std::cout << " -- Destructor called -- " << std::endl;
}

/**
 * @brief Overloaded assignment operator.
 * Copies the value from the source object.
 *
 * @param source The source object to copy.
 * @return Reference to the current object.
 */
Fixed &Fixed::operator=(const Fixed &source) {
    std::cout << GREEN << " -- Copy instance via operator overload -- " << RESET << std::endl;
    if (this != &source) {
        this->_value = source._value;
    }
    return *this;
}

/**
 * @brief Getter function for raw bits.
 * 
 * @return The raw bit value of the fixed-point number.
 */
int Fixed::getRawBits() const {
    std::cout << " -- getRawbits member function called: ";
    return _value;
}

/**
 * @brief Setter function for raw bits.
 * 
 * @param raw The raw bit value to set.
 */
void Fixed::setRawBits(int const raw) {
    std::cout << " -- setRawBits member function called" << std::endl;
    _value = raw;
}
