#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
    Cat();
    virtual ~Cat();
    Cat( Cat const & src ) ;  

    Cat &   operator=( Cat const & rhs);

    void makeSound() const ;

private:
    Brain *_brain;
};

#endif

