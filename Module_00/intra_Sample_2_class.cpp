
#include <iostream>
#include "intra_Sample_2_class.hpp"


// Constuctor contains the initialization list which does not assign only p1 to a1 value
// but also initialize it to it

Sample_2::Sample_2( char p1, int p2, float p3 , float const pi ): a1(p1), a2(p2), a3(p3), pi(pi) {
	std::cout << "____________________Sample_2_constructor____________________" << std::endl;
	
	std::cout << "Constructor Sample_2 called" << std::endl;

	std::cout << "This class is initializing the a1, a2 and a3 using an initialization list" <<  std::endl;
	std::cout << "See the intra_Sample_2_class.hpp definition of constructor " <<  std::endl;

	std::cout << "this->a1 = " << this->a1 << std::endl;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	std::cout << "this->a3 = " << this->a3 << std::endl;
	std::cout << "this->pi = " << this->pi << std::endl;

	std::cout << "____________________Sample_2_constructor_3__end_____________" << std::endl;
	return ;
};
	

Sample_2::~Sample_2( void ) {
	std::cout << "____________________Sample_2_deconstructor_____here_________" << std::endl;
};



void	Sample_2::member_function_const( void ) const {
	std::cout << "____________________Const Member function____________________" << std::endl;
	
	std::cout << "The member function of Sample_2 class is showing the use of " <<  std::endl;
	std::cout << "const with a member function as:" <<  std::endl;
	std::cout << "void member_function_const ( void ) const" <<  std::endl << std::endl;

	std::cout << "it allows to read and display an instance value of course as:" <<  std::endl << std::endl;
	std::cout << "this->a1 = " << this->a1 << std::endl;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	std::cout << "this->a3 = " << this->a3 << std::endl;
	std::cout << "this->pi = " << this->pi << std::endl;

	std::cout << "\n... but forbids any assignation to an instance value, which " <<  std::endl << std::endl;
	std::cout << "cannot be shown here as would not compile" <<  std::endl << std::endl;

	std::cout << "____________________Const Member function____end_____________" << std::endl;
	return ;
};
