// displayClass.hpp

#ifndef DISPLAYCLASS_H
#define DISPLAYCLASS_H

#include <iostream>
#include <string>

class Display {

	public:
		Display( void );
		~Display( void );
		static void welcomeMessage( void );
		static void displayMenu( void );
		static std::string  getUserInput ( void );
};

#endif // !DISPLAYCLASS_H

