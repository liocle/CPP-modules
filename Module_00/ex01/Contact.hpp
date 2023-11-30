#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>
# include <iomanip>
# include <unistd.h>
# include "BoxDrawing.hpp"
# include "Display.hpp"


// Forward declaration of the Contact class
class Contact;
/**
 * @brief A class representing a contact with basic information.
 *
 * This class stores and manages contact information, including first and last names,
 * nickname, phone number, and a "darkest secret." It provides methods for setting
 * and displaying contact details.
 *
 * @details
 * The class uses public and private access specifiers to control the visibility of
 * class members. Public members can be accessed from outside the class, while
 * private members are only accessible from within the class.
 */
class Contact {

public:
	/**
     * @brief Constructor for the Contact class.
     *
     * The constructor is a special member function called when an object of the
     * class is created. It initializes the object and can perform any setup
     * required. In this case, it prints a message indicating that the Contact module
     * is being initialized.
     */
    Contact(void);

    /**
     * @brief Destructor for the Contact class.
     *
     * The destructor is a special member function called when an object of the class
     * goes out of scope or is explicitly deleted. It is responsible for cleaning up
     * resources acquired by the object during its lifetime. In this case, it prints
     * a message indicating that the Contact module is being wiped.
     */
    ~Contact(void);
	
	/**
	 * @brief Set contact information for the Contact object.
	 *
	 * This function sets the contact information for a Contact object. The use of const in
	 * the parameter types ensures that the provided values are not modified within the function.
	 *
	 * @details
	 * - The use of const in front of the reference parameters ensures the safety of the function,
	 *   preventing unintended modifications to the passed arguments.
	 * - It also allows the function to work with the original data without making unnecessary copies,
	 *   optimizing performance, especially for large objects like strings.
	 * - Compatibility with constant objects: If you have a const instance of the Contact class and you
	 *   want to call setContactInfo on it, the function parameters being marked as const allows this operation.
	 *
	 * @see Contact
	 */
    void setContactInfo(const std::string &firstName, const std::string &lastName,
                        const std::string &nickName, const std::string &phoneNumber,
                        const std::string &darkestSecret);

	/**
	 * @brief Display contact information in a formatted list.
	 *
	 * This function displays the contact information in a formatted list. The function is marked as
	 * const to indicate that it does not modify the state of the Contact object.
	 *
	 * @param index The index of the contact in the list.
	 *
	 * @details
	 * - The function takes an index parameter to specify the position of the contact in the list.
	 * - The use of const at the end of the function signature indicates that this function does not
	 *   modify the internal state of the Contact object. It is a read-only operation.
	 *
	 * @see Contact
	 */
    void getContactList(int index) const;

	/**
	 * @brief Display detailed contact information.
	 *
	 * This function displays detailed information about the contact, including first name, last name,
	 * nickname, phone number, and darkest secret. The function is marked as const to indicate that it
	 * does not modify the internal state of the Contact object. It is a read-only operation.
	 *
	 * @see Contact
	 */
    void getContactInfo(void) const;

  private:
    static int	instanceCounter; // Static variable to count instances
	int			instanceId;

    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
};
#endif // !CONTACT_H
