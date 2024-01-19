#include "Color.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << YELLOW << "- Cure Constructor called -" << RESET << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other){
    std::cout << YELLOW << "- Cure Copy Constructor called -" << RESET << std::endl;
}

Cure::~Cure() {
    std::cout << YELLOW << "- Cure destructor called -" << RESET << std::endl;
}

Cure & Cure::operator=(const Cure &other) {
    std::cout << YELLOW << "- Cure Assignment Constructor called -" << RESET << std::endl;
    (void) other; 
    return *this;
}

AMateria *Cure::clone() const{
    std::cout << YELLOW << "- Cure::clone() called -" << RESET << std::endl;
    return (new Cure);
}

void Cure::use(ICharacter &target) {
    std::cout << YELLOW << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}
