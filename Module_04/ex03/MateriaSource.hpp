

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
    {
    private:
        AMateria *_knownMaterias[MAX_KNOWN_MATERIAS];
        
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource &operator=(const MateriaSource &other);
        virtual ~MateriaSource();


        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
    };
#endif
