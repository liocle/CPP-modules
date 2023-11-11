#ifndef INTRA_POINTER_TO_MEMBERS_CLASS_H
# define INTRA_POINTER_TO_MEMBERS_CLASS_H

/**
 * @brief The Sample class represents a sample object with a member variable and a member function.
 */
class Sample {

	public:
     	/**
        * @brief Public integer member variable.
        */
		int		foo;

		/**
		 * @brief Default constructor for Sample.
		 * @details Initializes the member variable foo to 0.
		 */
		Sample(void);
		/**
		 * @brief Destructor for Sample.
		 * @details Prints a message indicating the destruction of a Sample object.
		 */
		~Sample(void);

		/**
		 * @brief Member function that prints a message.
		 */
		void	bar(void) const;

};
#endif
