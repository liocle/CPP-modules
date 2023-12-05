#include "Fixed.hpp"

int main(void) {

    std::cout << BLUE << "Fixed a;\t\t// Default Constructor" << RESET << std::endl;
    Fixed a;
    std::cout << "a is " << a << std::endl;
    std::cout << YELLOW << "Fixed const b(10);\t// Int Constructor" << RESET << std::endl;
    Fixed const b(10);
    std::cout << RED << "Fixed const c(42.42f);\t// Float Constructor" << RESET << std::endl;
    Fixed const c(42.42f);
    std::cout << CYAN << "Fixed const d(b);\t// Copy Constructor" << RESET << std::endl;
    Fixed const d(b);
    std::cout << RED << "a = Fixed(1234.4321f);\t// Creates a temporary fixed object by calling Fixed constructor" << RESET << std::endl;
    std::cout << RED << "\t\t\t// Converts the float value passed to the constructor into a fixed-point number " << RESET << std::endl; 
    std::cout << RED << "\t\t\t// using 'roundf(value * (1 << _fractionalBits))' " << RESET << std::endl;
    std::cout << MAGENTA << "\t\t\t// temp object is assigned to instance 'a' using the overloaded operator assignment" << RESET << std::endl;
    std::cout << MAGENTA << "\t\t\t// which copies the '_value' of temp object into object 'a'" << RESET << std::endl;
    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}
