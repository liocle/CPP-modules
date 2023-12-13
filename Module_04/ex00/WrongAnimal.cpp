#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("Wrong Generic Animal") {
    std::cout << "WrongAnimal constructor called for " << _type << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src ) {
    std::cout << "WrongAnimal copy constructor called for " << _type << std::endl;
    *this = src;
    return;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called for " << _type << std::endl;
}

WrongAnimal &    WrongAnimal::operator=(WrongAnimal const & rhs) {
    std::cout << "WrongAnimal assignment operator called for " << _type << std::endl;
    if ( this != &rhs )
        this->_type = rhs.getType();
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}

