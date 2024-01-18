#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>

class ICharacter; // Forward declaration

class AMateria
    {
    private: AMateria();
        std::string type;

    protected:
        AMateria(const AMateria &other);

    public:
        virtual  ~AMateria();
        AMateria(std::string const & type);
        AMateria& operator=(const AMateria &other);

        std::string const & getType() const; //Returns the materia type
        
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
    };
#endif
