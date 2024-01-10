
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "- Cure Constructor called -" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other){
    std::cout << "- Cure Copy Constructor called -" << std::endl;
}

Cure::~Cure() {
    std::cout << "- Cure destructor called -" << std::endl;
}

Cure & Cure::operator=(const Cure &other) {
    std::cout << "- Cure Assignment Constructor called -" << std::endl;
    return *this;
}

AMateria *Cure::clone() const{
    return (new Cure);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl:;
}
