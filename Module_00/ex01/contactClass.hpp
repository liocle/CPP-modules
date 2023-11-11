#ifndef CONTACTCLASS_H
# define CONTACTCLASS_H

# include <string>
# include <iostream>


class Contact {

	public:
		Contact(void);
		~Contact(void);
		void	setContactInfo(const std::string &firstName, const std::string
				&lastName, const std::string &nickName,  const std::string 
				&phoneNumber, const std::string &darkestSecret);
		void	getContactList(int index) const;
		void	getContactInfo(void) const;

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
};
#endif // !CONTACTCLASS_H
