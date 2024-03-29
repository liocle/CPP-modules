#include <stdio.h>
#include <iostream>
#include "intra_sample_class.hpp"
#include "intra_Sample_1_class.hpp"
#include "intra_Sample_2_class.hpp"

int	gl_var = 1;
int	f(void) {return 2; }


namespace	Foo {

	int	gl_var = 3;
	int	f(void) {return 4; }
}


namespace	Bar {

	int	gl_var = 3;
	int	f(void) {return 6; }
}

namespace Muff = Bar ;


int	main (void)
{

	Sample instance;

	printf( "gl_var:			[%d]\n", gl_var );
	printf( "f():			[%d]\n\n", f() ); 

	printf( "Foo::gl_var:		[%d]\n", Foo::gl_var );
	printf( "Foo::f():		[%d]\n\n", Foo::f() ); 

	printf( "Bar::gl_var:		[%d]\n", Bar::gl_var );
	printf( "Bar::f():		[%d]\n\n", Bar::f() ); 

	printf( "Muff::gl_var:		[%d]\n", Muff::gl_var );
	printf( "Muff::f():		[%d]\n\n", Muff::f() ); 
	
	printf( "::gl_var:		[%d]\n", ::gl_var );
	printf( "::f():			[%d]\n", ::f() );


	char	buff[10];

	std::cout << "Enter a word: " << std::endl;
	std::cin >> buff;		
	std::cout << "The input word was " << buff << std::endl;
	
	std::cout << "Let's play with member attributes and member functions\nThose are defined in intra_sample_class.cpp. " << std::endl;  
	std::cout << "Let's initialize instance.foo " << std::endl;

	instance.foo = 21;
	std::cout << "instance.foo has been initialized to :" << instance.foo << std::endl;
	std::cout << "Lets call an instance of the instance.bar() in subsequence line" << std::endl;
	instance.bar();
	


	std::cout << "____________________Instance Sample_1 initialized manually____________________" << std::endl;
	Sample_1 instance1 ( 'a', 42, 4.2f );
	std::cout << "____________________Instance Sample_2 initialized automatically_______________" << std::endl;
	float const pi = 3.14;
	Sample_2 instance2 ( 'b', 21, 3.14f, pi);
	std::cout << "Let's test the " << std::endl;

	return (0);

}

