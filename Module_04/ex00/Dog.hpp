#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

/**
  * @class      Inherits from Animal class, representing specific types of animals.
  * @details    Inherits common properties and behaviors from the base class. 
  */
class Dog : public Animal {
public:
    Dog();                              // Initializes _type member according to Animal type, calls base class constructor implicitly
    Dog(Dog const & src);               // Copy constructor

    virtual ~Dog();                     // Virtual destructor to ensure proper cleanup if this class would be inherited from a derived class.
    Dog &   operator=(Dog const & rhs); // Assignment operator

    void makeSound() const;             // Overrides the makeSound function to provide specific sounds for each animal type.
};

#endif

