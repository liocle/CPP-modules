#include "phoneBookClass.hpp"
#include <iostream>
#include <string>

int main (void) 
{
	PhoneBook PhoneBook;

	std::cout << "Welcome to the 80s and their unbelievable technology" << std::endl;
	std::string input;
	do {
		std::cout << "Choose an action: " << std::endl;
		std::cout << "\tADD -> Add a contact" << std::endl;
		std::cout << "\tSEARCH -> Dox a contact" << std::endl;
		std::cout << "\tEXIT -> Quit and loose your friends" << std::endl;
		std::getline(std::cin, input);
		for (int i = 0; input[i] != '\0' ; i++)
			input[i] = std::toupper(input[i]);
		if (input.compare("ADD") == 0){
			PhoneBook.addContact();
		}
		else if (input.compare("SEARCH") == 0){
			PhoneBook.searchContact();
		}
		else if (input.compare("EXIT") == 0){ 
			break;
		}
 
	}
	while (input.compare("EXIT") != 0);

	return (0);
}
