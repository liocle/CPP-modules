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
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << std::endl;

    ////////////////////////////////////////////////////////////////////////////////
    std::cout << PURPLE << "Additional tests:" << RESET << std::endl;


    Fixed e(42);

    std::cout << "Initial values:" << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << Fixed::max(e, b) << std::endl;
    std::cout << Fixed::min(e, b) << std::endl;

    // Test increment and decrement operators
    std::cout << "\nIncrement and decrement:" << std::endl;
    Fixed c = e++; // Post-increment
    std::cout << "Fixed c = e++; // Post-increment " << std::endl;
    std::cout << "e (post-increment): " << e << std::endl;
    std::cout << std::setprecision(16) << "\tstd::setprecision(16) e(post-increment):\t\t" << e << std::endl;
    std::cout << "c (post-increment result): " << c << std::endl;
    std::cout << std::setprecision(16) << "\tstd::setprecision(16) c(post-increment):\t\t" << c << std::endl;

    
    Fixed d = ++a; // Pre-increment
    std::cout << "Fixed d = e++; // Post-increment " << std::endl;
    std::cout << "e (pre-increment): " << e << std::endl;
    std::cout << std::setprecision(16) << "\tstd::setprecision(16) e(post-increment):\t\t" << e << std::endl;
    std::cout << "d (pre-increment result): " << d << std::endl;
    std::cout << std::setprecision(16) << "\tstd::setprecision(16) d(post-increment):\t\t" << d << std::endl;

    // Test arithmetic operations
    std::cout << "\nArithmetic operations:" << std::endl;
    Fixed result_add = a + b;
    Fixed result_sub = a - b;
    Fixed result_mul = a * b;
    Fixed result_div = a / b;

    std::cout << "a + b: " << result_add << std::endl;
    std::cout << "a - b: " << result_sub << std::endl;
    std::cout << "a * b: " << result_mul << std::endl;
    std::cout << "a / b: " << result_div << std::endl;

    // Test comparisons
    std::cout << "\nComparisons:" << std::endl;
    bool greater_than = a > b;
    bool less_than = a < b;
    bool equal_to = a == b;

    std::cout << "a > b: " << (greater_than ? "true" : "false") << std::endl;
    std::cout << "a < b: " << (less_than ? "true" : "false") << std::endl;
    std::cout << "a == b: " << (equal_to ? "true" : "false") << std::endl;

    // Test static member functions
    std::cout << "\nStatic member functions:" << std::endl;
    Fixed min_result = Fixed::min(a, b);
    Fixed max_result = Fixed::max(a, b);

    std::cout << "min(a, b): " << min_result << std::endl;
    std::cout << "max(a, b): " << max_result << std::endl;
    std::cout << std::endl;

    return 0;
}
