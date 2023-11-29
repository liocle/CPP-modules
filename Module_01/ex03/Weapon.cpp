#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string weapon_type) { setType(weapon_type); }

Weapon::~Weapon() {}

const std::string &Weapon::getType(void) {
  std::string &reference_type = this->type;
  return (reference_type);
}

void Weapon::setType(std::string weapon_type) { this->type = weapon_type; }
