// displayClass.hpp

#ifndef DISPLAYCLASS_H
# define DISPLAYCLASS_H

# include <iostream>
# include <string>
# include "BoxDrawing.hpp"
# include "PhoneBook.hpp"

class Display {

	public:
		static void welcomeMessage( void );
		static void displayMenu( void );
		static void clearScreen( void );
		static void waitForKeypress( void );
		static std::string  getUserInput ( void );
};

#endif // !DISPLAYCLASS_H

