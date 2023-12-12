
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define RED  "\033[31m"

/**
 * @brief The ClapTrap class represents a generic robot with basic actions.
 */
class ClapTrap {
public:
    // Constructors and destructor
    /**
     * @brief Default constructor for ClapTrap.
     */
    ClapTrap(void);
    
    /**
     * @brief Parameterized constructor for ClapTrap.
     * @param name The name of the ClapTrap.
     */
    ClapTrap(std::string name);
    
    /**
     * @brief Copy constructor for ClapTrap.
     * @param other The ClapTrap object to copy.
     */
    ClapTrap(const ClapTrap &other);
    
    /**
     * @brief Destructor for ClapTrap.
     */
    ~ClapTrap();

    /**
     * @brief Assignment operator overload for ClapTrap.
     * @param other The ClapTrap object to assign.
     * @return A reference to the assigned ClapTrap object.
     */
    ClapTrap& operator=(const ClapTrap& other);
    
    // Member functions
    /**
     * @brief Attack the target, causing damage.
     * @param target The target to attack.
     */
    void attack(const std::string& target);
    
    /**
     * @brief Take damage and update hit points.
     * @param amount The amount of damage to take.
     */
    void takeDamage(unsigned int amount);
    
    /**
     * @brief Repair and update hit points.
     * @param amount The amount of hit points to gain.
     */
    void beRepaired(unsigned int amount);
    
    /**
     * @brief Set the attack damage of the ClapTrap.
     * @param amount The new attack damage value.
     */
    void setAttackDamage(unsigned int amount); 

private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

#endif
