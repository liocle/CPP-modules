
#include <iostream>
#include <iomanip>
#include <limits>
#include "contactClass.hpp"
#include "phoneBookClass.hpp"

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

		do {
			std::cout << "Enter First Name: ";
		} while (!get_line(firstName));
		do {
			std::cout << "Enter Last Name: ";
		} while (!get_line(lastName));
		do {
			std::cout << "Enter Nickname: ";
		} while (!get_line(nickName));
		do {
			std::cout << "Enter Phone Number: ";
		} while (!get_line(phoneNumber));
		do {
			std::cout << "Enter Darkest Secret: ";
		} while (!get_line(darkestSecret));

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
    std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
    std::cout << "│" << std::setw(10) << "Index" << "│" << std::setw(10) << "First Name" << "│"
              << std::setw(10) << "Last Name" << "│" << std::setw(10) << "Nickname" << "│" << std::endl;
    std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
}


void PhoneBook::printContacts() const {
    for (int i = 0; i < maxContacts && i < contactCount; i++) {
        contacts[i].getContactList(i);
    }
}

void PhoneBook::printContactFooter() const {
    std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}

void PhoneBook::getUserIndex(int &index) const {
    while (true) {
        std::cout << std::endl << "Enter the index of the contact to display: ";
        std::cin >> index;

        if (std::cin.fail() || index < 0 || index >= contactCount || index >= maxContacts) {
            std::cout << "Invalid index. Please enter a valid index." << std::endl;
            clearInputBuffer();
        } else {
			clearInputBuffer();
            break;
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
    } else {
        std::cout << "No contact in the phonebook." << std::endl;
    }
}
