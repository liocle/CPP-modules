#include <iostream>
#include "intra_non_member_class.hpp"

void	f0(void)
{
	Sample instance;

	std::cout << "-=_=-=_=-=_=-=_=-=_=-Called by f0=_=-=_=-=_=-=_=-=_=-=_=-=_=\nNumber of instances :" << Sample::getNumberInstances() << ":" << std::endl;
	return;
}


void	f1(void)
{
	Sample instance;

	std::cout << "-=_=-=_=-=_=-=_=-=_=-Called by main=_=-=_=-=_=-=_=-=_=-=_=-=_=\nNumber of instances :" << Sample::getNumberInstances() << ":" << std::endl;
	f0();
	return;
}


int	main() 
{
	std::cout << "-=_=-=_=-=_=-=_=-=_=main=_=-=_=-=_=-=_=-=_=-=_=-=_=\nNumber of instances :" << Sample::getNumberInstances() << ":" << std::endl;
	std::cout << "Let's call f1" << std::endl;
	f1();
	std::cout << "-=_=-=_=-=_=-=_=-=_=back to main=_=-=_=-=_=-=_=-=_=-=_=-=_=\nNumber of instances :" << Sample::getNumberInstances() << ":" << std::endl;
	return 0;
}


