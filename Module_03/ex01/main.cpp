#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {


    ClapTrap clapman;

    ScavTrap scav_guard("Da_GuaRD");
    ScavTrap random_guard;

    clapman.attack("Da_GuaRD");
    scav_guard.guardGate();
    random_guard.guardGate();

    scav_guard.attack("clapman");
    clapman.takeDamage(20) ;


    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    ClapTrap ClapTrapOverLord("FreakyClapStuff");
    ClapTrapOverLord.attack("clapman");
    scav_guard.guardGate();

    ScavTrap big_boss("JoJo_Da_GuaRD_oVeRLoRD");
    big_boss.attack("FreakyClapStuff");
    ClapTrapOverLord.takeDamage(20);

    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    ClapTrapOverLord = scav_guard;

    ClapTrapOverLord.setAttackDamage(1000);
    ScavTrap guard_2("An_other_guard");
    guard_2 = scav_guard;
    ClapTrapOverLord.attack("Da_GuaRD");
    guard_2.takeDamage(1000);
    guard_2.beRepaired(20);
    scav_guard.beRepaired(20);

    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    ClapTrapOverLord.attack("JoJo_Da_GuaRD_oVeRLoRD");
    big_boss.takeDamage(30);
    ClapTrapOverLord.setAttackDamage(100);
    ClapTrapOverLord.attack("JoJo_Da_GuaRD_oVeRLoRD");
    big_boss.takeDamage(100);
    big_boss.beRepaired(20);

    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    return 0;
}

