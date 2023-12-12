// FragTrap.cpp

#include "FragTrap.hpp"

// Constructors and destructor
FragTrap::FragTrap()  {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << RED << "🚀 FragTrap " << _name << " is ready for action! 💣" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << RED << "🚀 FragTrap " << _name << " is ready for action! 💣" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << RED << "🚀 FragTrap " << _name << " has been copied! 🤖" << RESET << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << RED << "🔥 FragTrap " << _name << " is no more! 💔" << RESET << std::endl;
}

// Assignment operator overload for FragTrap
FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);  // Call the base class assignment operator
    }    else 
    {
        std::cout << RED << "⚠️  ClapTrap ⚠️  class operator assignment failed: explicitely assigning value of variable to itself";
        std::cout << std::endl << "check your code and your compilation flags" << RESET << std::endl;
    }
    return *this;
}

// Special ability: high fives guys
void FragTrap::highFivesGuys(void) {
    std::cout << RED << "🖐  FragTrap " << _name << " gives high fives to everyone! 🖐" << RESET << std::endl;
}

