
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <limits>
#include "contactClass.hpp"
#include "phoneBookClass.hpp"
#include "boxDrawingClass.hpp"

PhoneBook::PhoneBook( void ) {
	// initialize the phone book array etc
	std::cout << "PhoneBook initialization..." << std::endl;
	contactCount = 0;
}

PhoneBook::~PhoneBook( void ) {
	//free contacts, phonebook
	std::cout << "Contact deletions" << std::endl << "PhoneBook erased" << std::endl;
}

int	get_line(std::string &str)
{
	std::getline(std::cin, str);
	if (str.empty())
		return (0);
	if (std::cin.eof())
		exit(0);
	return (1);
}

void PhoneBook::addContact(void) {
    Contact newContact;
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

    while (true) {
        std::cout << "Enter First Name: ";
        if (get_line(firstName))
            break;
        else
            std::cout << "Invalid input. Please enter a valid First Name." << std::endl;
    }

    while (true) {
        std::cout << "Enter Last Name: ";
        if (get_line(lastName))
            break;
        else
            std::cout << "Invalid input. Please enter a valid Last Name." << std::endl;
    }

    while (true) {
        std::cout << "Enter Nickname: ";
        if (get_line(nickName))
            break;
        else
            std::cout << "Invalid input. Please enter a valid Nickname." << std::endl;
    }

    while (true) {
        std::cout << "Enter Phone Number: ";
        if (get_line(phoneNumber))
            break;
        else
            std::cout << "Invalid input. Please enter a valid Phone Number." << std::endl;
    }

    while (true) {
        std::cout << "Enter Darkest Secret: ";
        if (get_line(darkestSecret))
            break;
        else
            std::cout << "Invalid input. Please enter a valid Darkest Secret." << std::endl;
    }

    newContact.setContactInfo(firstName, lastName, nickName, phoneNumber, darkestSecret);

    contacts[contactCount % maxContacts] = newContact;
    contactCount++;
}


void	PhoneBook::clearInputBuffer( void ) const {
	std::cin.clear();
	while (std::cin.get() != '\n');
}


void PhoneBook::printContactHeader() const {
    std::cout << std::endl << std::endl;

    std::cout << BoxDrawing::topLeftCorner;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << BoxDrawing::horizontalBorder;
		}
		std::cout << BoxDrawing::topDownSeparator;
	}

	for (int j = 0; j < 10; j++) {
		std::cout << BoxDrawing::horizontalBorder;
	}
    std::cout << BoxDrawing::topRightCorner << std::endl;


    std::cout << BoxDrawing::verticalBorder << std::setw(10) << "Index" << BoxDrawing::verticalBorder
              << std::setw(10) << "First Name" << BoxDrawing::verticalBorder
              << std::setw(10) << "Last Name" << BoxDrawing::verticalBorder
              << std::setw(10) << "Nickname" << BoxDrawing::verticalBorder << std::endl;
    std::cout << BoxDrawing::verticalLeftSeparator;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << BoxDrawing::horizontalBorder;
		}
		std::cout << BoxDrawing::innerSeparator;
	}

	for (int j = 0; j < 10; j++) {
		std::cout << BoxDrawing::horizontalBorder;
	}
    std::cout << BoxDrawing::verticalRightSeparator << std::endl;
}


void PhoneBook::printContacts() const {
    for (int i = 0; i < maxContacts && i < contactCount; i++) {
        contacts[i].getContactList(i);
    }
}

void PhoneBook::printContactFooter() const {

    std::cout << BoxDrawing::bottomLeftCorner;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << BoxDrawing::horizontalBorder;
		}
		std::cout << BoxDrawing::bottomUpSeparator;
	}

	for (int j = 0; j < 10; j++) {
		std::cout << BoxDrawing::horizontalBorder;
    }
    std::cout << BoxDrawing::bottomRightCorner << std::endl;
}


void PhoneBook::getUserIndex(int &index) const {
    while (true) {
        std::string userInput;
        std::cout << std::endl << "Enter the index of the contact to display: ";
        std::getline(std::cin, userInput);

        std::stringstream ss(userInput);
        ss >> index;

        // Check if the entire string is a valid integer
        if (ss.eof() && !ss.fail() && index >= 0 && index < contactCount && index < maxContacts) {
            break;
        } else {
            std::cout << "Invalid index. Please enter a valid index." << std::flush;
        }

    }
}

void PhoneBook::searchContact() const {
    if (contactCount > 0) {
        printContactHeader();
        printContacts();
        printContactFooter();

        int index;
        getUserIndex(index);
		if (contactCount > 0 && index < maxContacts)
			contacts[index].getContactInfo();
		// Clear the input buffer
		clearInputBuffer();
    } else {
        std::cout << "No contact in the phonebook." << std::endl;
    }
}
