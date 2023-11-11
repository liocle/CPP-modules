
#include <iostream>
#include "intra_Sample_1_class.hpp"



Sample_1::Sample_1( char p1, int p2, float p3) {
	std::cout << "____________________Sample_1_constructor____________________" << std::endl;
	
	std::cout << "Constructor Sample_1 called" << std::endl;

	std::cout << "This class is initializing the a1, a2 and a3 manually in the constructor" << std::endl;

	this->a1 = p1;
	std::cout << "this->a1 = " << this->a1 << std::endl;
	
	this->a2 = p2;
	std::cout << "this->a2 = " << this->a2 << std::endl;

	this->a3 = p3;
	std::cout << "this->a3 = " << this->a3 << std::endl;

	std::cout << "____________________Sample_1_constructor_3__end_____________" << std::endl;
	return ;
};
	

Sample_1::~Sample_1( void ) {
	std::cout << "____________________Sample_1_deconstructor_____here_________" << std::endl;
}
