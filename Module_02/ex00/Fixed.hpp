
#ifndef FIXED_HPP
# define FIXED_HPP

# include <string.h>
# include <iostream>
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define RED  "\033[31m"

/**
 * @brief Class representing a fixed-point number.
 * 
 * This class follows the canonical form for a C++ class, including a default
 * constructor, a copy constructor, an assignment operator overload, and a destructor.
 * It also provides getter and setter functions for raw bit manipulation.
 */
class Fixed {
public:
    Fixed(void);                                // Default Constructor.
    Fixed(const Fixed &source);                 // Copy constructor.
    ~Fixed(void);                               // Destructor. 
    Fixed   &operator = (const Fixed &source);  // Overloaded assignment operator.
    
    int     getRawBits(void) const;             // Getter function for the raw bits.
    void    setRawBits(int const raw);          // Setter function for the raw bits.
    

private:
    int                 _value;                 // Integer to store the value of the fixed-point number.
    static const int    _fractionalBits = 8;    // Number of bits in the fractional part.
};

#endif
