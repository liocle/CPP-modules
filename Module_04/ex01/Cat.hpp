#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal {
public:
    Cat();
    virtual ~Cat();
    Cat( Cat const & src ) ;  

    Cat &   operator=( Cat const & rhs);

    void    makeSound() const ;
    void    setIdea(unsigned int index, const std::string &idea);
    std::string getIdea(unsigned int index) const;

private:
    Brain *_brain;
};

#endif

