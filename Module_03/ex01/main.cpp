#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {


    ClapTrap clap_man1;

    ScavTrap scav_guard("Da_GuaRD");

    clap_man1.attack("Da_GuaRD");
    scav_guard.guardGate();

    scav_guard.attack("clap_man1");
    clap_man1.takeDamage(20) ;


    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    ClapTrap ClapTrapOverLord("Freaky_stuff");
    ClapTrapOverLord.attack("clap_man1");
    scav_guard.guardGate();

    ScavTrap big_boss("JoJo_Da_GuaRD_oVeRLoRD");
    big_boss.attack("Freaky_stuff");
    ClapTrapOverLord.takeDamage(20);

    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    ClapTrapOverLord = scav_guard;

    ScavTrap guard_2("An_other_guard");
    guard_2 = scav_guard;

    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    // Let the final battle begin!
    ClapTrapOverLord.attack("JoJo_Da_GuaRD_oVeRLoRD");
    big_boss.takeDamage(30);
    ClapTrapOverLord.setAttackDamage(100);
    ClapTrapOverLord.attack("JoJo_Da_GuaRD_oVeRLoRD");
    big_boss.takeDamage(100);
    big_boss.beRepaired(20);

    return 0;
}

