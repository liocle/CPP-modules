
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // Create instances of ClapTrap, ScavTrap, and FragTrap
    ClapTrap clapman;
    std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << std::endl;
    ScavTrap scav_guard("Da_GuaRD");
    std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << std::endl;
    FragTrap frag_dude("Frag_Dude");
    std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << std::endl;
    FragTrap anonymous_frag;
    std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << std::endl;


    frag_dude.highFivesGuys();
    frag_dude.attack("Da_GuaRD");
    scav_guard.takeDamage(30);
    scav_guard.attack("Frag_Dude");
    frag_dude.beRepaired(20);
  
    std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << std::endl;
    anonymous_frag = frag_dude;
    std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << std::endl;
    anonymous_frag.beRepaired(10);
    clapman = anonymous_frag;
    std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << std::endl;
    scav_guard.setAttackDamage(1000);
    scav_guard.attack("Frag_Dude");
    anonymous_frag.takeDamage(1000);
    anonymous_frag.highFivesGuys();

    std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << std::endl;

    return 0;
}

