#include "Color.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
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
    std::cout << LIGHT_BLUE << "- Ice::clone() called -" << RESET << std::endl;
    return (new Ice);
}

void Ice::use(ICharacter &target) {
    std::cout << LIGHT_BLUE << "* shoots an ice bolt at " << target.getName() << RESET << std::endl;
}
