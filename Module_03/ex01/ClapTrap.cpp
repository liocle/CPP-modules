#include "ClapTrap.hpp"

// Constructors and destructor
ClapTrap::ClapTrap() :
  _name("T0t0"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << GREEN << "Claptrap "<< _name << " is born with default delivery method 🎉" << RESET <<  std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << GREEN <<  "ClapTrap " << _name << " is born! 🎉" << RESET <<  std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    *this = other;
    std::cout << GREEN << "ClapTrap " << _name << " has been copied! 🤖" << RESET <<  std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << GREEN << "ClapTrap " << _name << " is no more! 💔" << RESET <<  std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) 
{
    std::cout << GREEN << "ClapTrap " << _name << " invoked operator assignment overload and will be named: ";
    _name = other._name; 
    std::cout << _name << std::endl;
    std::cout << "ClapTrap " << _name << "'s hit points level was\t" << _hitPoints << ", now is: ";
    _hitPoints = other._hitPoints;
    std::cout << _hitPoints << std::endl;
    std::cout << "ClapTrap " << _name << "'s energy points level was\t" << _energyPoints << ", now is: ";
    _energyPoints = other._energyPoints;
    std::cout << _energyPoints << std::endl;
    std::cout << "ClapTrap " << _name << "'s attack damage level was\t" << _attackDamage << ", now is: ";
    _attackDamage = other._attackDamage;
    std::cout << _attackDamage << RESET <<  std::endl;

  return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << GREEN << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! 💥" << std::endl;
        _energyPoints--;
    } else {
        std::cout << GREEN << "ClapTrap " << _name << " is out of energy! 😴" << std::endl;
    std::cout << RESET;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints > 0) {
        std::cout << GREEN << "ClapTrap " << _name << " takes " << amount << " points of damage! 😵" << std::endl;
        _hitPoints = (_hitPoints > amount) ? _hitPoints - amount : 0;
        if (_hitPoints == 0) {
            std::cout << "ClapTrap " << _name << " has run out of hit points and is down! 💔" << std::endl;
        }
    } else {
        std::cout << GREEN << "ClapTrap " << _name << " is already down! 😵" << std::endl;
    }
    std::cout << RESET;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        std::cout << GREEN << "ClapTrap " << _name << " is being repaired, gaining " << amount << " hit points! 🛠️" << std::endl;
        _hitPoints = amount;
        _energyPoints--;
    } else if (_hitPoints == 0) {
        std::cout << GREEN << "ClapTrap " << _name << " cannot be repaired, it has run out of hit points and is down! 💔" << std::endl;
    } else {
        std::cout << GREEN << "ClapTrap " << _name << " is out of energy for repairs! 😴" << std::endl;
    }
    std::cout << RESET;
}

void ClapTrap::setAttackDamage(unsigned int amount) {
    if (_hitPoints > 0 && _energyPoints > 0) {
       _attackDamage = amount;
       std::cout << GREEN << "ClapTrap " << _name << " increased its attack damage to " << _attackDamage << " points!" << std::endl;
       _energyPoints--;
    } else if (_hitPoints == 0) {
       std::cout << GREEN << "ClapTrap " << _name << " cannot be repaired; it has run out of hit points and is down! 💔" << std::endl;
    } else {
       std::cout << GREEN << "ClapTrap " << _name << " is out of energy for repairs! 😴" << std::endl;
    }
    std::cout << RESET;
}
