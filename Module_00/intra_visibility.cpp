#include <iostream>
#include "intra_visibility_class.hpp"

int main (void)
{
	Sample	instance;

	instance.publicFoo = 42;
	std::cout << "instance.publicFoo: " << instance.publicFoo << std::endl;

	std::cout << "________________________________________________________________________________" << std::endl;
	std::cout << "instance._privateFoo = 42; std::cout << \"instance._privateFoo: \" << instance._privatefoo << std::endl; \n\nAbove would not compile, because it is illegally calling for a private class member instead of calling it from the constructor itself itself" << std::endl;
	
	std::cout << "________________________________________________________________________________" << std::endl;
	instance.publicBar();

	return 0;
} 
