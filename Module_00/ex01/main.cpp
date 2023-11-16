#include "PhoneBook.hpp"
#include "Display.hpp"
#include <iostream>
#include <string>
#include <cstdlib>


int main() {
    PhoneBook phoneBook;
    std::string input;

    Display::welcomeMessage();

    while (input.compare("EXIT") != 0) {
        Display::displayMenu();
        input = Display::getUserInput();

        if (input.compare("ADD") == 0) {
            phoneBook.addContact();
        } else if (input.compare("SEARCH") == 0) {
            phoneBook.searchContact();
        } else if (input.compare("EXIT") == 0) {
            break;
        }
		Display::clearScreen();
        if (std::cin.eof())
            return 0;
    }

    return 0;
}

