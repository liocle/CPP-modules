#include "WrongCat.hpp"
# include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
    _type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src) {
    std::cout << "WrongCat copy constructor called for " << _type << std::endl;
}

WrongCat &  WrongCat::operator=(WrongCat const & rhs){
    std::cout << "WrongCat assignment operator called for " << _type << std::endl;
    if (this != &rhs) {
       this->_type = rhs.getType(); 
    }
    return *this;
}

WrongCat::~WrongCat() {
   std::cout << "WrongCat destructor called" << _type << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong Miaou! Miaou!" << std::endl;
}

