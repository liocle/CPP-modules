#ifndef PHONEBOOK_H
# define PHONEBOOK_H


# include <iostream>
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include <limits>
# include "BoxDrawing.hpp"

class Contact;
class Display;
class PhoneBook {

	public: 

		PhoneBook( void );
		~PhoneBook( void );
		void	addContact( void );
		void	searchContact( void ) const;
		static int		myGetLine(std::string &str);
		static const int	maxContacts = 8;

	private:
		static Contact				contacts[maxContacts];
		int					contactCount;
		void				clearInputBuffer( void ) const;
		void				printContactHeader( void ) const;
		void				printContacts( void ) const;
		void				printContactFooter( void ) const;
		void				getUserIndex( int &index) const;

};

#endif // !PHONEBOOK_H
