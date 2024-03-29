#include <iostream>
#include "intra_pointer_to_members_class.hpp"

int	main() {
	// Create an instance of the Sample class
	Sample	instance;
	// Create a pointer to the instance
	Sample	*instancePtr = &instance;
	
	// Declare a pointer to an integer member  variable of Sample
	int		Sample::*p = NULL;
	// Declare a pointer to a const member function of Sample
	void	(Sample::*f)(void) const;
	
	// Assign the pointer to the member variable 'foo' of Sample
	p = &Sample::foo;

	// Access and print the value of the member variable 'foo'
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	
	// Use the pointer to modify the vvalue of the mmember variable 'foo'
	instance.*p = 21;
	std::cout << "Value of member foo: " << instance.foo << std::endl;

	// Use the pointer through the instance pointer to modify 'foo'
	instancePtr->*p = 42;
	std::cout << "Value of member foo: " << instance.foo << std::endl;

	// Assign the pointer to the member function 'bar' of Sample 
	f = &Sample::bar;
	// Call the member function 'bar' through the instance
	(instance.*f)();
	// Call the member function 'bar' through the instance pointer
	(instancePtr->*f)();

	return 0;
}
