#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

/**
 * @brief The Dog class, derived from the Animal class.
 */
class Dog : public Animal {
public:
    Dog();
    /**
     * @brief Copy constructor.
     * Performs a deep copy of the dog, including its brain.
     * @param src The dog to copy.
     */
    Dog(Dog const & src);
    /**
     * @brief Virtual destructor.
     * Ensures proper cleanup, including the dog's brain.
     * Set virtual in case a derived Dog class would be instantiated in the future.
     */
    virtual ~Dog();
    /**
     * @brief Copy assignment operator.
     * Performs a deep copy of the dog, including its brain.
     * @param rhs The dog to copy.
     * @return Reference to the assigned dog.
     */
    Dog &   operator=(Dog const & rhs);
    /**
     * @brief Overrides the virtual function to make a dog sound.
     */
    void makeSound() const;
    /**
     * @brief Set an idea in the dog's brain.
     * @param index The index of the idea.
     * @param idea The idea to set.
     */
    std::string getIdea(unsigned int index) const;
    /**
     * @brief Get an idea from the dog's brain.
     * @param index The index of the idea.
     * @return The idea at the specified index.
     */
    void setIdea(unsigned int index, const std::string &idea);

private:
    Brain   *_brain;
};

#endif

