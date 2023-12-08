#include "Fixed.hpp"
#include <iomanip>
int main(void) {
 //    std::cout << "print float and objects with <iomanip> std::setprecision(16)" << std::endl;
 //    std::cout << std::setprecision(16) << "\tpi as float:\t\t" << pi << std::endl;
 //    std::cout << std::setprecision(16) << "\tpi as Fixed:\t\t" << piFixed << std::endl;

    std::cout << PURPLE << "Subject proposed main:" << RESET << std::endl;

    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << " <- corresponds to the smallest representable fraction 1/(2^8) = 1/256 provided by _fractionalBits set to 8" << std::endl;
    std::cout << a <<  std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << std::endl;

    ////////////////////////////////////////////////////////////////////////////////
    std::cout << PURPLE << "Additional tests:" << RESET << std::endl;


    std::cout << "Let's instantiate 'Fixed e(42)':" << std::endl;
    Fixed e(42);
    std::cout << "e:\t" << e << std::endl;
    std::cout << "b:\t" << b << std::endl;

    std::cout << "Test: Fixed::max(e, b): " << Fixed::max(e, b) << std::endl ;
    std::cout << std::endl << "Test: Fixed::min(e, b): " << Fixed::min(e, b) << std::endl ;
    // Test static member functions
    std::cout << "Let's instantiate 'Fixed min_result = Fixed::min(e, b)'";
    Fixed min_result = Fixed::min(e, b);
    std::cout << "min_result:\t" << min_result << std::endl;

    std::cout << "Let's instantiate 'Fixed max_result = Fixed::max(e, b)'";
    Fixed max_result = Fixed::max(e, b);
    std::cout << "max_result:\t" << max_result << std::endl;


    // Test increment and decrement operators
    std::cout << std::endl << "Test Increment and decrement:" << std::endl;
    std::cout << "Let's declare: Fixed c = e++;" ;
    Fixed c = e++; 
    std::cout << "c (assigned before incrementaion):\t" << c << std::endl;
    std::cout << "e (incremented after assignment):\t" << e << std::endl;

    
    std::cout << std::endl << "Let's declare: Fixed d = ++c;" ;
    Fixed d = ++c; 
    std::cout << "c (increment before assignement):\t" << c << std::endl;
    std::cout << "d (increment before assignement):\t" << d << std::endl;

    // Test arithmetic operations
    std::cout << "\nArithmetic operations:" << std::endl;
    std::cout << std::endl << "Let's instantiate 'Fixed result_add = e + b'" ;
    Fixed result_add = e + b;
    std::cout << "e =\t" << e << std::endl << "b =\t" << b << std::endl;
    std::cout << "e + b:\t" << result_add << std::endl;
    std::cout << std::endl << "Let's instantiate 'Fixed result_sub = e - b'" ;
    Fixed result_sub = e - b;
    std::cout << "e =\t" << e << std::endl << "b =\t" << b << std::endl;
    std::cout << "e - b:\t" << result_sub << std::endl;


    std::cout << std::endl << "Let's instantiate 'Fixed result_mul = e * b'" ;
    Fixed result_mul = e * b;
    std::cout << "e =\t" << e << std::endl << "b =\t" << b << std::endl;
    std::cout << "e * b:\t" << result_mul << std::endl;

    std::cout << std::endl << "Let's instantiate 'Fixed result_div = e / b'" ;
    Fixed result_div = e / b;
    std::cout << "e =\t" << e << std::endl << "b =\t" << b << std::endl;
    std::cout << "e / b:\t" << result_div << std::endl;

    // Test comparisons
    std::cout << "\nComparing 'e' and 'b':" << std::endl;
    std::cout << "e =\t" << e << std::endl << "b =\t" << b << std::endl;
    bool greater_than = e > b;
    bool less_than = e < b;
    bool equal_to = e == b;

    std::cout << "e > b:\t" << (greater_than ? "true" : "false") << std::endl;
    std::cout << "e < b:\t" << (less_than ? "true" : "false") << std::endl;
    std::cout << "e == b:\t" << (equal_to ? "true" : "false") << std::endl;

    std::cout << std::endl;

    return 0;
}
