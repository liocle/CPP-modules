
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <limits>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "BoxDrawing.hpp"
#include "Display.hpp"

/**
 * @brief Default constructor for the PhoneBook class.
 * @details Initializes the phone book array and prints an initialization message.
 */
PhoneBook::PhoneBook( void ) {
	std::cout << BoxDrawing::verticalBorder << std::endl;
	std::cout << BoxDrawing::bottomLeftCorner << BoxDrawing::horizontalBorder  << "→\t☏ PHONEB00K INITIALIZED with up to " << maxContacts << " contacts \n\n\t🆕  Includes darkest secret 🆕" << std::endl;
	contactCount = 0;
}

/**
 * @brief Destructor for the PhoneBook class.
 * @details Frees contacts and prints a message indicating that the phone book is erased.
 */
PhoneBook::~PhoneBook( void ) {
	std::cout << BoxDrawing::verticalLeftSeparator << "PhoneBook erased" << std::endl;
}

/**
 * @brief Helper function to get a line of input from the user.
 * @param str Reference to the string to store user input.
 * @return 0 if the input is empty or EOF is reached; 1 otherwise.
 */
int	get_line(std::string &str)
{
    std::getline(std::cin, str); // Read a line from the standard input and store it in the string 'str'
    if (str.empty()) // Check if the input string is empty
        return 0;
	return (1);
}

/**
 * @brief Adds a new contact to the phone book.
 * @details Prompts the user for contact information and adds the contact to the phone book.
 * After adding a contact, waits for a keypress.
 */
void PhoneBook::addContact(void) {
    Contact newContact;
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

    while (true) {
        std::cout << BoxDrawing::verticalLeftSeparator << "Enter First Name: ";
        if (get_line(firstName))
            break;
        else
            std::cout << BoxDrawing::verticalLeftSeparator << "Invalid input. Please enter a valid First Name." << std::endl;
    }

    while (true) {
        std::cout << BoxDrawing::verticalLeftSeparator << "Enter Last Name: ";
        if (get_line(lastName))
            break;
        else
            std::cout << BoxDrawing::verticalLeftSeparator << "Invalid input. Please enter a valid Last Name." << std::endl;
    }

    while (true) {
        std::cout << BoxDrawing::verticalLeftSeparator << "Enter Nickname: ";
        if (get_line(nickName))
            break;
        else
            std::cout << BoxDrawing::verticalLeftSeparator << "Invalid input. Please enter a valid Nickname." << std::endl;
    }

    while (true) {
        std::cout << BoxDrawing::verticalLeftSeparator << "Enter Phone Number: ";
        if (get_line(phoneNumber))
            break;
        else
            std::cout << BoxDrawing::verticalLeftSeparator << "Invalid input. Please enter a valid Phone Number." << std::endl;
    }

    while (true) {
        std::cout << BoxDrawing::verticalLeftSeparator << "Enter Darkest Secret: ";
        if (get_line(darkestSecret))
            break;
        else
            std::cout << BoxDrawing::verticalLeftSeparator << "Invalid input. Please enter a valid Darkest Secret." << std::endl;
    }

    newContact.setContactInfo(firstName, lastName, nickName, phoneNumber, darkestSecret);

    contacts[contactCount % maxContacts] = newContact;
    contactCount++;
	Display::waitForKeypress();

}

/**
 * @brief Clears the input buffer.
 * @details Clears the input buffer by discarding any unwanted characters until a newline character is encountered.
 */
void PhoneBook::clearInputBuffer( void ) const {
    std::cin.clear(); // Clear the error flags that may be set on the input stream. Error flags are set when there's a mismatch between the expected input type and the actual input.
    while (std::cin.get() != '\n'); // Reads and discards characters from the input stream (std::cin) until a newline character ('\n') is encountered. This is a way to clear any remaining characters in the input buffer
}

/**
 * @brief Prints the header for displaying contacts in a formatted table.
 * @details Uses BoxDrawing characters to create a stylized table header.
 */
void PhoneBook::printContactHeader() const {

    std::cout << BoxDrawing::verticalLeftSeparator;

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

/**
 * @brief Prints the contacts in a formatted table.
 * @details Uses BoxDrawing characters to create a stylized table of contacts.
 */
void PhoneBook::printContacts() const {
    for (int i = 0; i < maxContacts && i < contactCount; i++) {
        contacts[i].getContactList(i);
    }
}

/**
 * @brief Prints the footer for displaying contacts in a formatted table.
 * @details Uses BoxDrawing characters to create a stylized table footer.
 */
void PhoneBook::printContactFooter() const {

    std::cout << BoxDrawing::verticalLeftSeparator;

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

/**
 * @brief Gets the user's choice of contact index to display.
 * @param index Reference to the integer to store the selected contact index.
 */
void PhoneBook::getUserIndex(int &index) const {
    while (true) {
        std::string userInput;
        std::cout << BoxDrawing::verticalBorder << " Choose contact index to display: ";
        
        // Read a line of input from the user
        std::getline(std::cin, userInput);

        // Create a stringstream to perform formatted input operations on the string
        std::stringstream ss(userInput);

        // Attempt to extract an integer from the stringstream and store it in 'index'
        ss >> index;

        // Check if the entire string is a valid integer
		// ss.eof checks if the stringstream has reached eof, if yes, integer extraction was succesfull
		// ss.fail flag set to ensure that there was no failure during the extraction (in case that it would contains a non-integer character)
        if (ss.eof() && !ss.fail() && index >= 0 && index < contactCount && index < maxContacts) {
            break; // Exit the loop if the input is valid
        } else {
            std::cout << BoxDrawing::verticalBorder << " Invalid index. Please enter a valid index." << std::endl;
        }
    }
}

/**
 * @brief Searches and displays the contact information based on user input.
 * @details Prints the contacts, prompts the user for an index, and displays the contact information.
 * If no contacts are available, it prints a message indicating that the phone book is empty.
 */
void PhoneBook::searchContact() const {
	int index;

    if (contactCount > 0) {
        printContactHeader();
        printContacts();
        printContactFooter();

        getUserIndex(index);
		if (contactCount > 0 && index < maxContacts)
			contacts[index].getContactInfo();
		// Clear the input buffer
		clearInputBuffer();
    } else {
        std::cout << "No contact in the phonebook." << std::endl;
    }
}
