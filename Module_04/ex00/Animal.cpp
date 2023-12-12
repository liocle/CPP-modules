#include "Animal.hpp"

Animal::Animal() : type("Generic Animal") {
    std::cout << "Animal constructor called for " << type << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called for " << type << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Meta animal sound" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

