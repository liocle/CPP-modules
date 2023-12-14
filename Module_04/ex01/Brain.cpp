
#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain() { std::cout << "-- Brain constructor called" << std::endl; }

Brain::~Brain() { std::cout << "-- Brain destructor called" << std::endl; }

Brain::Brain(const Brain &other) {
    std::cout << "-- Brain copy contructor using deep copy" << std::endl;
    for (int i = 0; i < 100; i++) {
        _ideas[i] = other._ideas[i];
    }
}

Brain &Brain::operator=(Brain const &other) {
    std::cout << "-- Brain assignment operator using deep copy" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            _ideas[i] = other._ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(unsigned int index, const std::string &idea) {
    if (index < 100) {
        _ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index < 100)
        return (_ideas[index]);
    return ("-- Not a valid index");
}

