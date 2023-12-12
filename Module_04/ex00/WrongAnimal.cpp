#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong Generic Animal") {
    std::cout << "WrongAnimal constructor called for " << type << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called for " << type << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

