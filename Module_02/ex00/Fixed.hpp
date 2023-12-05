
#ifndef FIXED_HPP
# define FIXED_HPP

# include <string.h>
# include <iostream>
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define RED  "\033[31m"


class Fixed {
public:
    Fixed(void);
    Fixed(const Fixed &source);
    ~Fixed(void);
    
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    
    Fixed   &operator = (const Fixed &source);

private:
    int                 _value;
    static const int    _fractionalBits = 8;
};

#endif
