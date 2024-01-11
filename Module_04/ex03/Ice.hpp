
#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"


class Ice : public AMateria {
public:
    Ice();
    ~Ice();
    Ice(const Ice &other);
    Ice &operator=(const Ice &other);

    AMateria *clone() const override;
    void use(ICharacter &target) override;
};

#endif
