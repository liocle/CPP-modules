#include "Fixed.hpp"


int main ( void ) 
{
    std::cout << std::endl;
    std::cout << "Instance_a initialized to 0 as" << BLUE << "'Fixed instance_a'" << RESET <<  "using default constructor:" << std::endl;
    Fixed instance_a;

    std::cout << std::endl << std::endl;
    std::cout << "Instance_b initialized to 0 as " << CYAN << "'Fixed instance_b(instance_a)'" << RESET << " using copy constructor:" << std::endl;
    Fixed instance_b(instance_a);

    std::cout << std::endl << std::endl;
    std::cout << "Instance_a initialized to 0 as" << BLUE << "'Fixed instance_c'" << RESET <<  "using default constructor:" << std::endl;
    Fixed instance_c;
    std::cout << "Instance_c is now set as " << GREEN << "'instance_a = instance_b'" << RESET << " using operator overload" << std::endl;
    instance_c = instance_b;



    std::cout << std::endl;
    std::cout << "instance_a = " << instance_a.getRawBits() <<  std::endl;
    std::cout << "instance_b = " << instance_b.getRawBits() <<  std::endl;
    std::cout << "instance_c = " << instance_c.getRawBits() <<  std::endl;
    
    std::cout << std::endl << RED << "Setting a new value, 42, to instance_a: ";
    instance_a.setRawBits(42);
    std::cout << "instance_a.setRawBits(42)" << RESET << std::endl;
    
    std::cout << std::endl;
    std::cout << "Instance_d initialized to 42 as " << CYAN << "'Fixed instance_d(instance_a)'" << RESET << " using copy constructor:" << std::endl;
    Fixed instance_d(instance_a);
    
    std::cout << GREEN << "Updating instance_b = instance_c = instance_a with operator overload" << RESET << std::endl;
    instance_b = instance_c = instance_a;
    std::cout << "instance_a = " << instance_a.getRawBits() <<  std::endl;
    std::cout << "instance_b = " << instance_b.getRawBits() <<  std::endl;
    std::cout << "instance_c = " << instance_c.getRawBits() <<  std::endl;
    std::cout << "instance_d = " << instance_d.getRawBits() <<  std::endl;


    std::cout << std::endl << std::endl;


}
