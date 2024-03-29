#include <iostream>
#include "intra_sample_class.hpp"

Sample::Sample(void) {

	int instance;

	std::cout << "________________________________________________________________________________" << std::endl;
	std::cout << "Constructor called -> Starting initialization" << std::endl;
	std::cout << "Let's initialize the member foo, using this->foo pointer pointing to current instance" << std::endl;
	this->foo = 42;
	std::cout << "this->foo: " << this->foo << std::endl;
	
	std::cout << "let's do the same with this->bar() " << std::endl;
	this->bar();;
	std::cout << "Constructor called -> Instance initialized" << std::endl;
	std::cout << "________________________________________________________________________________" << std::endl;
	return;
}

Sample::~Sample(void) {
	std::cout << "________________________________________________________________________________" << std::endl;
	std::cout << "\nDestructor called -> leaving the scope instance is destructed" << std::endl;
	std::cout << "________________________________________________________________________________" << std::endl;
	return;
}

void	Sample::bar(void) {
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" <<std::endl; 
	std::cout << "\nMember function: 'bar' is displaying this line" << std::endl;
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" <<std::endl; 
	return;

}
