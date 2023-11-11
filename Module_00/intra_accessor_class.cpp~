
#include <iostream>
#include "intra_accessor_class.hpp"

Accessor::Accessor( void ) {
	
	std::cout << "Constructor called" << std::endl;
	
	this->setFoo( -1 );
	std::cout << "this->getFoo() from Constructor: " << this->getFoo() << std::endl;
	
	return;
}

Accessor::~Accessor( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

int	Accessor::getFoo(void ) const {

	return this->_foo;
}

void Accessor::setFoo( int v ) {

	if ( v >= -1 )
		this->_foo = v;
	else
		std::cout << "\t*** Only positive values admitted ***" << std::endl;

	return;
}
	
