#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

/**
 * @brief The Cat class, derived from the Animal class.
 */
class Cat : public Animal {
public:
    /**
     * @brief Default constructor.
     * Initializes the cat type and brain.
     */
    Cat();
    /**
     * @brief Destructor.
     * Ensures proper cleanup, including the cat's brain.
     */
    virtual ~Cat();
    /**
     * @brief Copy constructor.
     * Performs a deep copy of the cat, including its brain.
     * @param src The cat to copy.
     */    
    Cat( Cat const & src ) ;  
    /**
     * @brief Copy assignment operator.
     * Performs a deep copy of the cat, including its brain.
     * @param rhs The cat to copy.
     * @return Reference to the assigned cat.
     */
    Cat &   operator=( Cat const & rhs);

    /**
     * @brief Overrides the virtual function to make a cat sound.
     */
    void    makeSound() const ;
    /**
     * @brief Set an idea in the cat's brain.
     *
     * @param index The index of the idea.
     * @param idea The idea to set.
     */
    void    setIdea(unsigned int index, const std::string &idea);
    std::string getIdea(unsigned int index) const;

private:
    Brain *_brain;
};

#endif

