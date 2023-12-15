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
    Cat();
    /**
     * @brief   Virtual destructor.
     * Ensures proper cleanup, including the cat's brain.
     * Set as virtual in the eventuality of a derived class being implemented from it in future.
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
     * @param index The index of the idea.
     * @param idea The idea to set.
     */
    void    setIdea(unsigned int index, const std::string &idea);
    /**
     * @brief Get an idea from the cat's brain.
     * @param index The index of the idea.
     * @return The idea at the specified index.
     */
    std::string getIdea(unsigned int index) const;

private:
    Brain *_brain;
};

#endif

