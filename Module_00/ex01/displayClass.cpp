// displayClass.cpp

#include "displayClass.hpp"

Display::Display( void ) {
	std::cout << "Initializing display module..." << std::endl;
}
	
Display::~Display( void ) {
	std::cout << "Display module switching off..." << std::endl;
}


void Display::welcomeMessage() {
    std::cout << "Welcome to the 80s and their unbelievable technology" << std::endl;
}

void Display::displayMenu() {
    std::cout << "Choose an action: " << std::endl;
    std::cout << "\tADD -> Add a contact" << std::endl;
    std::cout << "\tSEARCH -> Dox a contact" << std::endl;
    std::cout << "\tEXIT -> Quit and lose your friends" << std::endl;
}

std::string Display::getUserInput() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

