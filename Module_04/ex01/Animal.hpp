#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
    Animal();
    Animal( Animal const & src );
    Animal &    operator=( Animal const & rhs);

    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;

protected:
    std::string _type;
};

#endif

