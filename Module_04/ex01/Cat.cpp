#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal(), _brain(new Brain) {
    _type = "Cat";
    std::cout << "--- Cat constructor called" << std::endl;
}

Cat::Cat( Cat const & src ) : Animal(src), _brain(new Brain(*src._brain)) {
    std::cout << "--- Cat copy constructor called for " << _type << std::endl;
}

Cat::~Cat() {
    std::cout << "--- Cat destructor called" << std::endl;
    delete _brain;
}

Cat &    Cat::operator=(Cat const & rhs) {
    std::cout << "--- Cat assignment operator called for " << _type << std::endl;
    if ( this != &rhs ){
        this->_type = rhs.getType();
        delete _brain;
        _brain = new Brain(*rhs._brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Miaou! Miaou!" << std::endl;
}

void    Cat::setIdea(unsigned int index, const std::string &idea) {
    _brain->setIdea(index, idea);
}

std::string Cat::getIdea(unsigned int index) const {
    return (_brain->getIdea(index));
}


