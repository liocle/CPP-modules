#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public AAnimal {
public:
    Cat();
    Cat( Cat const & src ) ;  
    virtual ~Cat();

    Cat &   operator=( Cat const & rhs);

    void    makeSound() const ;
    void    setIdea(unsigned int index, const std::string &idea);
    std::string getIdea(unsigned int index) const;

private:
    Brain *_brain;
};

#endif

