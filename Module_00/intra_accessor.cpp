#include <iostream>
#include "intra_accessor_class.hpp"

int	main() {

	Accessor	instance;

	std::cout << "____________________________________________________________" << std::endl;
	std::cout << "Value of _Foo via the accessor before initialization: :" << instance.getFoo() << ":" << std::endl;
	
	std::cout << "\n____________________________________________________________" << std::endl;
	std::cout << "Setting Foo to '42'" << std::endl;
	instance.setFoo(42);

	std::cout << "Value of _Foo after setting it to '42' : :" << instance.getFoo() << ":" << std::endl;


	std::cout << "\n____________________________________________________________" << std::endl;
	std::cout << "Setting Foo to '-42'" << std::endl;
	instance.setFoo(-42);

	std::cout << "Value of _Foo after setting it to '42' : :" << instance.getFoo() << ":" << std::endl;

	std::cout << "\n____________________________________________________________" << std::endl;

	return 0;
}


