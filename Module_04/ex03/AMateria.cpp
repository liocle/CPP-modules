#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Color.hpp"


AMateria::~AMateria() {
    std::cout << GREEN << "- AMateria Constructor called of type - "<< this->type << RESET << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type) {
    std::cout << GREEN << "- AMateria Constructor called of given type - " << this->type << RESET << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type) {
    std::cout << GREEN << "- AMateria Copy Constructor called of given type - " << this->type << RESET << std::endl;

}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

std::string const & AMateria::getType() const {
    return (this->type);
}

void AMateria::use(ICharacter &target)
{
    std::cout << GREEN << "AMateria is not meant to be used..." << target.getName() << " I would have set it as a pure function if not obliged to use this function signature" << RESET << std::endl;
}

