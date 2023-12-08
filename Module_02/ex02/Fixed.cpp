#include "Fixed.hpp"

/**
 * @brief Default constructor for the Fixed class.
 * Initializes the value to 0.
 */
Fixed::Fixed() : _value(0) {
  std::cout << BLUE << " -- Default constructor called -- " << RESET
            << std::endl;
}

/**
 * @brief   Int constructor for the Fixed class.
 * Converts the provided integer value into a fixed-point representation.
 * @details value is left-shifted by _fractionalBits. It multiplies the integer
 * by 2 raised to the power of "_fractionalBits" = 256, shifting the bits to
 * represent the fractional part of the fixed-point number and store it in
 * instances' _value.
 * @param value The integer value to be converted.
 */
Fixed::Fixed(const int value) : _value(value << _fractionalBits) {
  std::cout << YELLOW << " -- Int constructor called -- " << RESET << std::endl;
}

/**
 * @brief   Float constructor for the Fixed class.
 * Converts the provided floating-point value into a fixed-point representation.
 * @details The provided floating-point is multiplied by "(1 <<
 * _fractionalBits)", equivalent to multiply by 2 raised ot power of
 * "_fractionalBits" = 256, converting the floating-point value into a
 * fixed-point representation. The "roundf" is used to round the result to the
 * nearest integer value, to ensure the the fixed-point representation is
 * accurate in _value.
 * @param   value The floating-point value to be converted.
 */
Fixed::Fixed(const float value)
    : _value(roundf(value * (1 << _fractionalBits))) {
  std::cout << RED << " -- Float constructor called -- " << RESET << std::endl;
}

/**
 * @brief Copy constructor for the Fixed class.
 * Copies the value from the source instance to the newly created instance.
 * @param source The source Fixed instance.
 */
Fixed::Fixed(const Fixed &source) : _value(source._value) {
  std::cout << CYAN
            << " -- Copy constructor called, source's _value set to copied "
               "instance's value -- "
            << RESET << std::endl;
}

/**
 * @brief Destructor for the Fixed class.
 */
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/**
 * @brief Overloaded assignment operator for the Fixed class.
 * Copies the value from the source instance to the current instance.
 * @param source The source Fixed instance.
 * @return Reference to the current Fixed instance.
 */
Fixed &Fixed::operator=(const Fixed &source) {
  std::cout << MAGENTA << " -- Copy assignment operator called -- " << RESET
            << std::endl;
  if (this != &source) {
    this->_value = source._value;
  }
  return (*this);
}

/**
 * @brief   Get the integer representation of the fixed-point number.
 * @details _value represents the fixed-point number, _fractionalBits
 * represents the number of bits reserved for the fractional part.
 * "_value >> _fractionalBits" performs a right shift on _value removing
 * the fractional bits and keeping only the integer part.
 *
 * @return  Integer representation of the fixed-point number.
 */
int Fixed::toInt() const { return (_value >> _fractionalBits); }

/**
 * @brief   Get the floating-point representation of the fixed-point number.
 * @details _value is cast to a float using static_cast<float>(_value). Allows
 * floating-point division without integer division truncation.
 * "1 << _fractionalBits" is a bitwise left shift creating a divisor where the
 * fractional part is represented oas a power of 2.
 * @return  Floating-point representation of the fixed-point number.
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

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Overloaded > operator for Fixed instances.
 * @param other The Fixed instance to compare against.
 * @return True if the current instance is greater than the other, false
 * otherwise.
 */
bool Fixed::operator>(const Fixed &other) const {
  return (_value > other._value);
}
/**
 * @brief Overloaded < operator for Fixed instances.
 * @param other The Fixed instance to compare against.
 * @return True if the current instance is less than the other, false otherwise.
 */
bool Fixed::operator<(const Fixed &other) const {
  return (_value < other._value);
}
/**
 * @brief Overloaded >= operator for Fixed instances.
 * @param other The Fixed instance to compare against.
 * @return True if the current instance is greater than or equal to the other,
 * false otherwise.
 */
bool Fixed::operator>=(const Fixed &other) const {
  return (_value >= other._value);
}
/**
 * @brief Overloaded <= operator for Fixed instances.
 * @param other The Fixed instance to compare against.
 * @return True if the current instance is less than or equal to the other,
 * false otherwise.
 */
bool Fixed::operator<=(const Fixed &other) const {
  return (_value <= other._value);
}

/**
 * @brief Overloaded == operator for Fixed instances.
 * @param other The Fixed instance to compare against.
 * @return True if the current instance is equal to the other, false otherwise.
 */
bool Fixed::operator==(const Fixed &other) const {
  return (_value == other._value);
}

/**
 * @brief Overloaded != operator for Fixed instances.
 * @param other The Fixed instance to compare against.
 * @return True if the current instance is not equal to the other, false
 * otherwise.
 */
bool Fixed::operator!=(const Fixed &other) const {
  return (_value != other._value);
}

/**
 * @brief Overloaded + operator for Fixed instances.
 * @param other The Fixed instance to add.
 * @return The result of the addition.
 */
Fixed Fixed::operator+(const Fixed &other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

/**
 * @brief Overloaded - operator for Fixed instances.
 * @param other The Fixed instance to subtract.
 * @return The result of the subtraction.
 */
Fixed Fixed::operator-(const Fixed &other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

/**
 * @brief Overloaded * operator for Fixed instances.
 * @param other The Fixed instance to multiply.
 * @return The result of the multiplication.
 */
Fixed Fixed::operator*(const Fixed &other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

/**
 * @brief Overloaded / operator for Fixed instances.
 * @param other The Fixed instance to divide by.
 * @return The result of the division.
 */
Fixed Fixed::operator/(const Fixed &other) const {
  return Fixed(this->toFloat() / other.toFloat());
}

/**
 * @brief Overloaded pre-increment operator for Fixed instances.
 * @return Reference to the current Fixed instance.
 */
Fixed &Fixed::operator++(void) { 
  this->_value++;
  return *this;
}

/**
 * @brief Overloaded pre-decrement operator for Fixed instances.
 * @return Reference to the current Fixed instance.
 */
Fixed &Fixed::operator--(void) {
  this->_value--;
  return *this;
}

/**
 * @brief Overloaded post-increment operator for Fixed instances.
 * @param unused Dummy parameter to distinguish between pre-increment and
 * post-increment.
 * @return A copy of the Fixed instance before the increment.
 */
Fixed Fixed::operator++(int) { 
  Fixed ret_instance = *this;
  this->_value++;
  return ret_instance;
}

/**
 * @brief Overloaded post-decrement operator for Fixed instances.
 * @param unused Dummy parameter to distinguish between pre-decrement and
 * post-decrement.
 * @return A copy of the Fixed instance before the decrement.
 */
Fixed Fixed::operator--(int) {
  Fixed ret_instance = *this;
  this->_value--;
  return ret_instance;
}

/**
 * @brief Static member function to find the minimum of two Fixed instances.
 * @param a The first Fixed instance.
 * @param b The second Fixed instance.
 * @return The minimum of the two Fixed instances.
 */
Fixed Fixed::min(const Fixed &a, const Fixed &b) { return ((a < b) ? a : b); }

/**
 * @brief Static member function to find the maximum of two Fixed instances.
 * @param a The first Fixed instance.
 * @param b The second Fixed instance.
 * @return The maximum of the two Fixed instances.
 */
Fixed Fixed::max(const Fixed &a, const Fixed &b) { return ((a > b) ? a : b); }
