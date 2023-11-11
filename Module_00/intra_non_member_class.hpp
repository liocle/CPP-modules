
#ifndef INTRA_NON_MEMBER_CLASS_H
# define INTRA_NON_MEMBER_CLASS_H

class Sample {

	public:
		Sample( void );
		~Sample( void );
/**
 * @brief Gets the number of instances of Sample.
 * @details Static member functions can be called on the class itself
 * without needing an instance. This function returns the total count
 * of Sample instances created.
 * @return The number of instances.
 */
		static int	getNumberInstances( void );
/**
 * @brief The number of instances of Sample.
 * @details Static members belong to the class itself, not to instances
 * of the class. This static variable keeps track of the total count of
 * Sample instances created.
 */
	private:
		static int	_NumberInstances;
};

#endif
