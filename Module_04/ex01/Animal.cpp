#include <iostream>
#include "Animal.hpp"

Animal::Animal() : _type("Generic Animal") {
    std::cout << "- Animal constructor called for " << _type << std::endl;
}

Animal::~Animal() {
    std::cout << "- Animal destructor called for " << _type << std::endl;
}

Animal::Animal( Animal const & other ) : _type(other._type) {
    std::cout << "- Animal copy constructor called for " << _type << std::endl;
    return;
}

Animal &    Animal::operator=(Animal const & other) {
    std::cout << "- Animal assignment operator called for " << _type << std::endl;
    if ( this != &other ){
        this->_type = other.getType();
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}

