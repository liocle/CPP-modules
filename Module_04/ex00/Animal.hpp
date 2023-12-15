#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

/**
  * @brief    The Animal class serves as the base class for all animals.
  * It encapsulates common properties and behaviors that are shared among animals. 
  */
class Animal {
public:
    Animal();                                   // Default contstructor initializes the _type member with a default value.
    virtual ~Animal();                          // Virtual destructor to ensure a proper cleanup when deleting objects through bas class pointers.

    Animal( Animal const & src );               // Copy constructor
    Animal &    operator=( Animal const & rhs); // Assignment operator 

    virtual void makeSound() const;             // Virtual function makeSound declared to be overridden by derived class objects.
    std::string getType() const;                // Getter function set as const

protected:
    std::string _type;                          // Common property to all Animal objects

};

#endif

