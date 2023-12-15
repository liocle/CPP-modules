#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Generic Animal") {
    std::cout << "Animal constructor called for " << _type << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called for " << _type << std::endl;
}

Animal::Animal( Animal const & src ) {
    std::cout << "Animal copy constructor called for " << _type << std::endl;
    *this = src;
    return;
}

Animal &    Animal::operator=(Animal const & rhs) {
    std::cout << "Animal assignment operator called for " << _type << std::endl;
    if ( this != &rhs )
        this->_type = rhs.getType();
    return *this;

}

void Animal::makeSound() const {
    std::cout << "Meta animal sound" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}

