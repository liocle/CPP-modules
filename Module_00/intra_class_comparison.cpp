#include <iostream>
#include "intra_class_comparison_class.hpp"

int	main () {

	Sample instance1( 42 );
	Sample instance2( 21 );
	Sample instance3( 42 );


	if (&instance1 == &instance1 )
		std::cout << "&instance1 and &instance1 are physically equal" << std::endl;
	else 
		std::cout << "&instance1 and &instance1 are not physically equal" << std::endl;

	if (&instance1 == &instance2 )
		std::cout << "&instance1 and &instance2 are physically equal" << std::endl;
	else 
		std::cout << "&instance1 and &instance2 are not physically equal" << std::endl;

	if (&instance1 == &instance3 )
		std::cout << "&instance1 and &instance3 are physically equal" << std::endl;
	else 
		std::cout << "&instance1 and &instance3 are not physically equal" << std::endl;

	if (instance1.compare( &instance1 ) == 0 )
		std::cout << "instance1 and instance1 are structurally equal" << std::endl;
	else 
		std::cout << "instance1 and instance1 are not structurally equal" << std::endl;

	if (instance1.compare( &instance2 ) == 0 )
		std::cout << "instance1 and instance2 are structurally equal" << std::endl;
	else 
		std::cout << "instance1 and instance2 are not structurally equal" << std::endl;

	if (instance1.compare( &instance3 ) == 0 )
		std::cout << "instance1 and instance3 are structurally equal" << std::endl;
	else 
		std::cout << "instance1 and instance3 are not structurally equal" << std::endl;

	return 0;
}
