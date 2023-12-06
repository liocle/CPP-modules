#include "Fixed.hpp"
#include <iomanip>

int main(void) {

    std::cout << BLUE << "Fixed a;\t\t// Default Constructor" << RESET << std::endl;
    Fixed a;
    std::cout << "a is " << a << std::endl;
    std::cout << YELLOW << "Fixed const b(10);\t// Int Constructor" << RESET << std::endl;
    Fixed const b(10);
    std::cout << RED << "Fixed const c(42.42f);\t// Float Constructor (creates a Fixed object with the value 42.42)" << RESET << std::endl;
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


    std::cout << std::endl;
    std::cout << "Let's define pi as a float whose fractional part is longer than our defined" << std::endl;

    std::cout << "_fractionalBits = 8, and an Fixed object piFixed which will take the pi " << std::endl;
    std::cout << "float as arg, namely:" << std::endl << PURPLE << " -- float pi = 3.14159265358979323846f; --"  << RESET << std::endl;
    float pi = 3.14159265358979323846f;
    std::cout << RED << "Fixed piFixed = pi\t//Take float as argument which will be truncated" << RESET << std::endl;
    Fixed piFixed = pi;                     // Conversion from float to Fixed using constructor
 
    std::cout << "print float and objects with standard std::cout precision after decimal point" << std::endl;
    std::cout << "-> std::cout << pi as float: << pi << std::endl; // prints float normally " << std::endl;
    std::cout << "\tpi as float:\t\t" << pi << std::endl;
    std::cout << "-> std::cout << pi as Fixed: << pi << std::endl; // gets _value using toFloat() via the overloaded operator <<" << std::endl;
    std::cout << "\tpi as Fixed:\t\t" << piFixed << std::endl;

    std::cout << "print float and objects with <iomanip> std::setprecision(16)" << std::endl;
    std::cout << std::setprecision(16) << "\tpi as float:\t\t" << pi << std::endl;
    std::cout << std::setprecision(16) << "\tpi as Fixed:\t\t" << piFixed << std::endl;

    
    return 0;
}
