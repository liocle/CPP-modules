
#include "PhoneBook.hpp"
#include "Contact.hpp"

int Contact::instanceCounter = 0;
Contact::Contact(void) {
	instanceCounter++;
	this->instanceId = instanceCounter;
	if (this->instanceId == 1) {
		Display::clearScreen();
		std::string warning = "  ‼ Warning, the device is LOADING and may get HOT ‼  ";
		std::cout << std::endl;

		// Print menu string top box
		std::cout << BoxDrawing::menuTopLeftCorner << "╒";
 		for (int i = 0; i < (int)warning.size() - 3; i++) {
			std::cout << BoxDrawing::menuHorizontalBorder << "═" ;
		}
		std::cout << BoxDrawing::menuTopRightCorner << "╕" << std::endl; ;
		// Print menu string within the box
		std::cout << BoxDrawing::menuVerticalBorder << "│" << warning << " " << BoxDrawing::menuVerticalBorder  << "│" << std::endl;
		// Print menu string bottom box
		std::cout << BoxDrawing::menuBottomLeftCorner <<  "╘";
		for (int i = 0; i < (int)warning.size() - 3; i++) {
			std::cout << BoxDrawing::menuHorizontalBorder << "═" ;
		}
		std::cout << BoxDrawing::menuVerticalRightSeparator << "╡"<< std::endl;

		for (int i = 0; i < (int)warning.size() - 2; i++) {
			std::cout << " ";	
		}
		std::cout << BoxDrawing::verticalBorder << "│" << std::endl;
		
		for (int i = 0; i < (int)warning.size() - 2; i++) {
			if (i == 0)
				std::cout << BoxDrawing::topLeftCorner << "┌";
			else 
				std::cout << BoxDrawing::vanishingHorizontalLine << "╴";
		}
		std::cout << BoxDrawing::bottomRightCorner << "┘" << std::endl;

		std::cout << BoxDrawing::verticalBorder << "│"<< std::endl;
		std::cout << BoxDrawing::verticalLeftSeparator << "├" << "Contact module\t\t\t(#" << this->instanceId << ")\tINITIALIZED" << std::endl;
	}
	else {
        if (instanceId <= PhoneBook::maxContacts)
        {
            std::cout << "├" << "Contact module\t\t\t(#" << this->instanceId << ")\tINITIALIZED" << std::endl;
        }
        else 
            std::cout << BoxDrawing::verticalLeftSeparator << "Contact module\t\t\t(#" << this->instanceId << ")\tINITIALIZED" << std::endl;
		sleep(1);
	}
	return ;
}

Contact::~Contact(void) {
	usleep(50000);
		std::cout << BoxDrawing::vanishingVerticalLine << "Contact module <" << this->instanceId << "> wiped..." << std::endl;
		
	return ;
}	

void	Contact::setContactInfo(const std::string &firstName, const std::string
		&lastName, const std::string &nickName,  const std::string 
		&phoneNumber, const std::string &darkestSecret){

	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

void	Contact::getContactList(int index) const {
	std::cout << "│" << std::setw(10) << index << "│" << std::setw(10) << 
		(firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName)
		<< "│" << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) 
				+ "." : lastName) << "│" << std::setw(10) << (nickName.length() > 10 ?
					nickName.substr(0, 9) + '.' : nickName) << "│" << std::endl;
}

void	Contact::getContactInfo(void) const {
	std::cout << BoxDrawing::verticalBorder << std::endl;
	std::cout << BoxDrawing::verticalBorder << std::setw(20) << "First Name:\t" << firstName << std::endl;
	std::cout << BoxDrawing::verticalBorder << std::setw(20) << "Last Name:\t" << lastName << std::endl;
	std::cout << BoxDrawing::verticalBorder << std::setw(20) << "Nickname:\t" << nickName <<  std::endl;
	std::cout << BoxDrawing::verticalBorder << std::setw(20) << "Phone number:\t" << phoneNumber  <<  std::endl;
	std::cout << BoxDrawing::verticalBorder << std::setw(20) << "Darkest secret:\t" << darkestSecret  << std::endl;
	std::cout << BoxDrawing:: menuBottomLeftCorner;
	for (int i = 0; i < 44; i++) {
		std::cout << BoxDrawing::menuHorizontalBorder;
	}
	std::cout << std::endl;

	Display::waitForKeypress();

}



