// FragTrap.hpp

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

/**
 * @brief The FragTrap class represents a robot derived from ClapTrap with additional features.
 */
class FragTrap : public ClapTrap {
public:
    FragTrap(void);
    /**
     * @brief Default constructor for FragTrap.
     * @param name The name of the FragTrap.
     */
    FragTrap(std::string name);

    /**
     * @brief Copy constructor for FragTrap.
     * @param other The FragTrap object to copy.
     */
    FragTrap(const FragTrap& other);

    /**
     * @brief Destructor for FragTrap.
     */
    ~FragTrap();

    /**
     * @brief Assignment operator overload for FragTrap.
     * @param other The FragTrap object to assign.
     * @return A reference to the assigned FragTrap object.
     */
    FragTrap& operator=(const FragTrap& other);

    /**
     * @brief Special ability of FragTrap: high fives guys.
     */
    void highFivesGuys(void);
};

#endif

