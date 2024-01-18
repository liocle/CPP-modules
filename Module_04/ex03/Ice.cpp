#include "Color.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria("cure") {
    std::cout << LIGHT_BLUE << "- Ice Constructor called -" << RESET << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other){
    std::cout << LIGHT_BLUE << "- Ice Copy Constructor called -" << RESET << std::endl;
}

Ice::~Ice() {
    std::cout << LIGHT_BLUE << "- Ice destructor called -" << RESET << std::endl;
}

Ice & Ice::operator=(const Ice &other) {
    std::cout << LIGHT_BLUE << "- Ice Assignment Constructor called -" << RESET << std::endl;
    (void) other; 
    return *this;
}

AMateria *Ice::clone() const{
    return (new Ice);
}

void Ice::use(ICharacter &target) {
    std::cout << LIGHT_BLUE << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}
