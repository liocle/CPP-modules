#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
    _type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( Cat const & src ) : Animal(src) {
    std::cout << "Cat copy constructor called for " << _type << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat &    Cat::operator=(Cat const & rhs) {
    std::cout << "Cat assignment operator called for " << _type << std::endl;
    if ( this != &rhs )
        this->_type = rhs.getType();
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Miaou! Miaou!" << std::endl;
}

