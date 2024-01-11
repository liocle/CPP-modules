
#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include   <string>
# include   "AMateria.hpp"
# define     MAX_KNOWN_MATERIAS 4

class IMateriaSource
    {
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
    };

#endif
