#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
    Animal();
    Animal( Animal const & src );               // Copy constructor, performs deep copy of Animal's type
    Animal &    operator=( Animal const & rhs); 

    virtual ~Animal();                          // Virtual destructor to ensure proper cleanup when derived classes are destroyed

    virtual void makeSound() const;             // Virtual makeSound() to ensure the derived classes express themselves properly
    std::string getType() const;

protected:
    std::string _type;
};

#endif

