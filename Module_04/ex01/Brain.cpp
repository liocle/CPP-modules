
#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain & other){
    std::cout << "Brain copy contructor using deep copy" << std::endl;
    for (int i = 0; i < 100; i++){
        _ideas[i] = other._ideas[i];
    }
}

Brain & Brain::operator=(Brain const & other){
    std::cout << "Brain assignment operator using deep copy" << std::endl;
    if (this != &other){
        for (int i = 0; i < 100; i++){
            _ideas[i] = other._ideas[i];
        }
    }
    return *this;
}

