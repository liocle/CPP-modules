#include "ScavTrap.hpp"

// Constructors and destructor
ScavTrap::ScavTrap() : ClapTrap() {
    _name = "a_guard";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << BLUE << "ScavTrap " << _name << " is born with a mission! 🔒" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout  << BLUE << "ScavTrap " << _name << " is born with a mission! 🔒" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout  << BLUE << "ScavTrap " << _name << " has been copied! 🤖" << RESET << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout  << BLUE << "ScavTrap " << _name << " is deactivated, mission complete! 🏁"<< RESET  << std::endl;
}

// Member function
void ScavTrap::guardGate() {
    std::cout  << BLUE << "ScavTrap " << _name << " enters gatekeeper mode! 🔒"<< RESET  << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << BLUE << "ScavTrap " << _name << " attacks " << target << " with a special attack, causing " << _attackDamage << " points of damage! 💥" << std::endl;
        _energyPoints--;
    } else {
        std::cout << BLUE << "ScavTrap " << _name << " is out of energy! 😴" << std::endl;
    }
    std::cout << RESET;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
{
    std::cout << BLUE << "ScavTrap " << _name << " invoked operator assignment overload and will be named: ";
    _name = other._name; 
    std::cout << _name << std::endl;
    std::cout << "ScavTrap " << _name << "'s hit points level was\t" << _hitPoints << ", now is: ";
    _hitPoints = other._hitPoints;
    std::cout << _hitPoints << std::endl;
    std::cout << "ScavTrap " << _name << "'s energy points level was\t" << _energyPoints << ", now is: ";
    _energyPoints = other._energyPoints;
    std::cout << _energyPoints << std::endl;
    std::cout << "ScavTrap " << _name << "'s attack damage level was\t" << _attackDamage << ", now is: ";
    _attackDamage = other._attackDamage;
    std::cout << _attackDamage << RESET <<  std::endl;

  return *this;
}
    if (this != &other) {
        ClapTrap::operator=(other);  // Call the base class assignment operator

    }
    return *this;
}

