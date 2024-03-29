#include <iostream>
#include "intra_non_member_class.hpp"

Sample::Sample( void ){

	std::cout << "Constructor called" << std::endl;
	Sample::_NumberInstances += 1;

	return;
}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	Sample::_NumberInstances -= 1;

	return;
}

int	Sample::getNumberInstances( void ) {
	return Sample::_NumberInstances;
}

int	Sample::_NumberInstances = 0;
