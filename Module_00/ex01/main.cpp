#include "phoneBookClass.hpp"
#include <iostream>
#include <string>

int main (void) 
{
	PhoneBook PhoneBook;

	std::cout << "Welcome to the 80s and their unbelievable technology" << std::endl;
	std::string input;
	while (input.compare("EXIT") != 0)
	{
		std::cout << "Choose an action: " << std::endl;
		std::cout << "\tADD -> Add a contact" << std::endl;
		std::cout << "\tSEARCH -> Dox a contact" << std::endl;
		std::cout << "\tEXIT -> Quit and loose your friends" << std::endl;
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0){
			PhoneBook.addContact();
		}
		else if (input.compare("SEARCH") == 0){
			PhoneBook.searchContact();
		}
		else if (input.compare("EXIT") == 0){ 
			break;
		}
		if (std::cin.eof())
			return (0);
	}

	return (0);
}
