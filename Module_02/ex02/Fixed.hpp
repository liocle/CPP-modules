
#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define RED  "\033[31m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define PURPLE "\033[1;4;35m"

/**
 * @brief Class representing a fixed-point number.
 * 
 * This class follows the canonical form for a C++ class, including a default
 * constructor, a copy constructor, an assignment operator overload, and a destructor.
 * It also provides getter and setter functions for raw bit manipulation.
 * Additionally, the << operator is overloaded to allow a meaningful representation
 * of Fixed objects when printed to the standard output.
 */
class Fixed {
public:
    Fixed(void);                                // Default Constructor.
    Fixed(const int _value);
    Fixed(const float _value);
    Fixed(const Fixed &source);                 // Copy constructor.
    ~Fixed(void);                               // Destructor. 
    
    Fixed   &operator = (const Fixed &source);  // Overloaded assignment operator.
    
    int             toInt(void) const;          // Right shift to get the integer value from the fixed-point representation
    float           toFloat(void) const;        // Convert fixed-point representation to float by dividing by 2^_fractionalBits
    static Fixed    min(const Fixed &a, const Fixed &b);
    static Fixed    max(const Fixed &a, const Fixed &b);

    // Comparaison
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmétique
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Incrémentation et décrémentation
    Fixed &operator++();                        // Pré-incrémentation
    Fixed operator++(int);                      // Post-incrémentation
    Fixed &operator--();                        // Pré-décrémentation
    Fixed operator--(int);                      // Post-décrémentation

private:
    int                 _value;                 // Integer to store the value of the fixed-point number.
    static const int    _fractionalBits = 8;    // Number of bits dedicated to the fractional part.
};

/**
 * @brief   Overloading the << operator for output stream
 *          Outputs the floating-point representation of the Fixed instance.
 * @details Operator overloading is the ability to provide custom implementations for the standard operators beased on the data 
 * they operate on. When an operator is overloaded for a specific class, it defines how instance of that class should behave 
 * with that operator. General Syntax:
 *      -- ReturnTYpe operatorSymbol(parameters);
 * 
 * Here it is a non-member overloading as the left operand is an object of a class or not (compare with Fixed &operator+ above)
 * @param   out Output stream.
 * @param   fixed The Fixed instance to be output.
 * @return  Reference to the output stream.
 */
std::ostream   &operator<<(std::ostream &out, const Fixed &fixed);

#endif
