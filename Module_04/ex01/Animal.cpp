#include <iostream>
#include "Animal.hpp"

Animal::Animal() : _type("Generic Animal") {
    std::cout << "Animal constructor called for " << _type << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called for " << _type << std::endl;
    delete _brain;
}

Animal::Animal( Animal const & src ) {
    std::cout << "Animal copy constructor called for " << _type << std::endl;
    *this = src;
    return;
}

Animal &    Animal::operator=(Animal const & other) {
    std::cout << "Animal assignment operator called for " << _type << std::endl;
    if ( this != &other ){
        this->_type = other.getType();
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Meta animal sound" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}

