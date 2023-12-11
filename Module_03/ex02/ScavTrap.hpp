/**
 * @file ScavTrap.hpp
 * @brief Definition of the ScavTrap class.
 */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/**
 * @class ScavTrap
 * @brief Represents a robot derived from ClapTrap with additional features.
 */
class ScavTrap : public ClapTrap {
public:
    /**
     * @brief Default constructor for ScavTrap.
     */
    ScavTrap(void);
    
    /**
     * @brief Parameterized constructor for ScavTrap.
     * @param name The name of the ScavTrap.
     */
    ScavTrap(std::string name);
    
    /**
     * @brief Copy constructor for ScavTrap.
     * @param other The ScavTrap object to copy.
     */
    ScavTrap(const ScavTrap& other);
    
    /**
     * @brief Destructor for ScavTrap.
     */
    ~ScavTrap();

    /**
     * @brief Assignment operator overload for ScavTrap.
     * @param other The ScavTrap object to assign.
     * @return A reference to the assigned ScavTrap object.
     */
    ScavTrap& operator=(const ScavTrap& other);

    /**
     * @brief Attack the target, causing damage.
     * @param target The target to attack.
     */
    void attack(const std::string& target);

    /**
     * @brief Activate gatekeeper mode.
     */
    void guardGate();
};

#endif

