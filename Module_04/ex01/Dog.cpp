#include "Dog.hpp"

Dog::Dog() : Animal() {
    _type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( Dog const & src ) : Animal (src) {
    std::cout << "Dog copy constructor called for " << _type << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog &    Dog::operator=(Dog const & rhs) {
    std::cout << "Dog assignment operator called for " << _type << std::endl;
    if ( this != &rhs )
        this->_type = rhs.getType();
    return *this;

}

void Dog::makeSound() const {
    std::cout << "Ouaf! Ouaf!" << std::endl;
}

