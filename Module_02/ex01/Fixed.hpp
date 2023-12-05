
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


class Fixed {
public:
    Fixed(void);                                // Default Constructor.
    Fixed(const int _value);
    Fixed(const float _value);
    Fixed(const Fixed &source);                 // Copy constructor.
    ~Fixed(void);                               // Destructor. 
    
    Fixed   &operator = (const Fixed &source);  // Overloaded assignment operator.
    
    int     toInt(void) const;                  // .
    float   toFloat(void) const;                // .
    

private:
    int                 _value;                 // Integer to store the value of the fixed-point number.
    static const int    _fractionalBits = 8;    // Number of bits in the fractional part.
};

// Overloading the << operator for output stream
std::ostream   &operator<<(std::ostream &out, const Fixed &fixed);

#endif
