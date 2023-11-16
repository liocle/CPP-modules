#ifndef PHONEBOOKCLASS_H
# define PHONEBOOKCLASS_H

# include "contactClass.hpp"

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

#endif // !PHONEBOOKCLASS_H
