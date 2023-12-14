#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(Dog const & src);

    virtual ~Dog();
    Dog &   operator=(Dog const & rhs);

    void makeSound() const;
    std::string getIdea(unsigned int index) const;
    void setIdea(unsigned int index, const std::string &idea);

private:
    Brain   *_brain;
};

#endif

