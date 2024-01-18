#include "AMateria.hpp"
#include "ICharacter.hpp"



AMateria::~AMateria() {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(const AMateria &other) : type(other.type) {}

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
    std::cout << "AMateria is not meant to be used..." << target.getName() << " I would have set it as a pure function if not obliged to use this function signature" << std::endl;
}

