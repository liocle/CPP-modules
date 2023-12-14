#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Generic AAnimal") {
    std::cout << "- AAnimal constructor called for " << _type << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "- AAnimal destructor called for " << _type << std::endl;
}

AAnimal::AAnimal( AAnimal const & other ) : _type(other._type) {
    std::cout << "- AAnimal copy constructor called for " << _type << std::endl;
    return;
}

AAnimal &    AAnimal::operator=(AAnimal const & other) {
    std::cout << "- AAnimal assignment operator called for " << _type << std::endl;
    if ( this != &other ){
        this->_type = other.getType();
    }
    return *this;
}

// void AAnimal::makeSound() const {
//     std::cout << "AAnimal sound" << std::endl;
// }

std::string AAnimal::getType() const {
    return _type;
}

