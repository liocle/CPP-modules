
#include <iostream>
#include <iomanip>
#include "contactClass.hpp"
#include "phoneBookClass.hpp"

PhoneBook::PhoneBook( void ) {
	std::cout << "PhoneBook initialization..." << std::endl;
	contactCount = 0;
	// initialize the phone book array etc
}

PhoneBook::~PhoneBook( void ) {
	std::cout << "Contact deletions" << std::endl << "PhoneBook erased" << std::endl;
	//free contacts, phonebook
}

void PhoneBook::addContact(void) {
    if (contactCount < 8) {
        Contact newContact;
        std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

        std::cout << "Enter First Name: ";
        std::getline(std::cin, firstName);
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, lastName);
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, nickName);
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, phoneNumber);
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, darkestSecret);

        newContact.setContactInfo(firstName, lastName, nickName, phoneNumber, darkestSecret);

        contacts[contactCount] = newContact;
        contactCount++;
    } else {
        // Replace the oldest contact if the array is full
        std::cout << "PhoneBook is full. Replacing the oldest contact." << std::endl;
        contacts[contactCount % 8] = Contact();  // Create a new Contact to replace the oldest one
		contactCount++;

    }
	std::cout << "Contact count: " << contactCount << std::endl;
}

void	PhoneBook::searchContact(void) const {
	if (contactCount > 0) {
		std::cout << std::endl << std::endl;
		std::cout << " - - - - - - - - - - - - - - - - - - - - - -  " << std::endl;
		std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
		std::cout << " - - - - - - - - - - - - - - - - - - - - - -  " << std::endl;
		for (int i = 0; i < contactCount; i++) {
			contacts[i].getContactList(i);
		}
		std::cout << " - - - - - - - - - - - - - - - - - - - - - -  " << std::endl;

		int index;		
		std::cout << std::endl << "Enter the index of the contact to display: ";
		std::cin >> index;

		if (index >= 0 && index < contactCount)
			contacts[index].getContactInfo();
		else
			std::cout << "Invalid index." << std::endl;
	} else {
		std::cout << "No contacts in the phonebook." << std::endl;
	}
}	
