#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria("cure") {
    std::cout << "- Ice Constructor called -" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other){
    std::cout << "- Ice Copy Constructor called -" << std::endl;
}

Ice::~Ice() {
    std::cout << "- Ice destructor called -" << std::endl;
}

Ice & Ice::operator=(const Ice &other) {
    std::cout << "- Ice Assignment Constructor called -" << std::endl;
    (void) other; 
    return *this;
}

AMateria *Ice::clone() const{
    return (new Ice);
}

void Ice::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
