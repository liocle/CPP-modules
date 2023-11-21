#ifndef PHONEBOOK_H
# define PHONEBOOK_H


# include <iostream>
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include <limits>
# include "BoxDrawing.hpp"
# include "Contact.hpp"
# include "Contact.hpp"
# include "Display.hpp"

class PhoneBook {

	public: 

		PhoneBook( void );
		~PhoneBook( void );
		void	addContact( void );
		void	searchContact( void ) const;

	private:
		static const int	maxContacts = 8;
		Contact				contacts[maxContacts];
		int					contactCount;
		void				clearInputBuffer( void ) const;
		void				printContactHeader( void ) const;
		void				printContacts( void ) const;
		void				printContactFooter( void ) const;
		void				getUserIndex( int &index) const;

};

#endif // !PHONEBOOK_H
