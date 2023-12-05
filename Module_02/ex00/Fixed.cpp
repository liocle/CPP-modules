#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << BLUE << " -- Default constructor called, initialized _value to to 0 -- " << RESET << std::endl;
}

Fixed::Fixed(const Fixed &source) : _value(source._value) {
    std::cout << CYAN << " -- Copy constructor called, source's _value set to copied instance's value -- " << RESET << std::endl;
}

Fixed::~Fixed() {
    std::cout << " -- Destructor called -- " << std::endl;
}

Fixed &Fixed::operator=(const Fixed &source) {
    std::cout << GREEN << " -- Copy instance via operator overload -- " << RESET << std::endl;
    if (this != &source) {
        this->_value    = source._value;
    }
    return *this;
}

int     Fixed::getRawBits() const {
    std::cout << " -- getRawbits member function called: ";
    return _value;
}

void    Fixed::setRawBits(int const raw) {
    std::cout << " -- setRawBits member function called" << std::endl;
    _value = raw;
}

