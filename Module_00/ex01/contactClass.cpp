
#include <iostream>
#include <iomanip>
#include "contactClass.hpp"

int Contact::instanceCounter = 0;
Contact::Contact(void) {
	instanceCounter++;
	std::cout << "Contact module (#" << instanceCounter << ") initialized..." << std::endl;
	return ;
}

Contact::~Contact(void) {
	std::cout << "Contact module <" << instanceCounter << "> wiped..." << std::endl;
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
	std::cout << std::endl;
	std::cout << std::setw(20) << "First Name:\t< " << firstName << " >" << std::endl;
	std::cout << std::setw(20) << "Last Name:\t< " << lastName << " >" << std::endl;
	std::cout << std::setw(20) << "Nickname:\t< " << nickName << " >" << std::endl;
	std::cout << std::setw(20) << "Phone number:\t< " << phoneNumber << " >" <<  std::endl;
	std::cout << std::setw(20) << "Darkest secret:\t< " << darkestSecret << " >" << std::endl;
	std::cout << std::endl;
}



