#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

/**
  * @class      Inherits from Animal class, representing specific types of animals.
  * @details    Inherits common properties and behaviors from the base class. 
  */
class Cat : public Animal {
public:
    Cat();                                  // Initializes _type member according to Animal type, calls base class constructor implicitly
    virtual ~Cat();                         // Virtual destructor to ensure proper cleanup if this class would be inherited from a derived class.// Virtual destructor to ensure proper cleanup if this class would be inherited from a derived class.

    Cat( Cat const & src ) ;                // Copy constructor

    Cat &   operator=( Cat const & rhs);    // Virtual destructor to ensure proper cleanup if this class would be inherited from a derived class.

    void makeSound() const ;                // Overrides the makeSound function to provide specific sounds for each animal type.
};

#endif
