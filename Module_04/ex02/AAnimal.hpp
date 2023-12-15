#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal {
public:
    AAnimal();
    AAnimal( AAnimal const & src );
    AAnimal &    operator=( AAnimal const & rhs);

    virtual ~AAnimal();
    /**
     * @brief Pure virtual function to make the animal produce a sound.
     * This makes AAnimal an abstract class.
     */
    virtual void makeSound() const = 0;
    std::string getType() const;

protected:
    std::string _type;
};

#endif

