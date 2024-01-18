#include "Color.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << LIGHT_GREEN << "- Cure Constructor called -" << RESET << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other){
    std::cout << LIGHT_GREEN << "- Cure Copy Constructor called -" << RESET << std::endl;
}

Cure::~Cure() {
    std::cout << LIGHT_GREEN << "- Cure destructor called -" << RESET << std::endl;
}

Cure & Cure::operator=(const Cure &other) {
    std::cout << LIGHT_GREEN << "- Cure Assignment Constructor called -" << RESET << std::endl;
    (void) other; 
    return *this;
}

AMateria *Cure::clone() const{
    return (new Cure);
}

void Cure::use(ICharacter &target) {
    std::cout << LIGHT_GREEN << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}
