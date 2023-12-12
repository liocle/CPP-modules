#include "ClapTrap.hpp"
#include <string> 
#include <iostream>


int main() {
    std::cout << "Testing constructors and basic actions:" << std::endl;
    ClapTrap T0t0; // Default constructor
    ClapTrap Bob("Bob"); // Parameterized constructor

    T0t0.attack("Bob");
    std::cout << RED ; 
    Bob.takeDamage(0);
    Bob.attack("T0t0");
    std::cout << RESET;
    T0t0.takeDamage(0);
    T0t0.setAttackDamage(5); //increase attack damage
    T0t0.attack("Bob");
    std::cout << RED ; 
    Bob.takeDamage(5);
    Bob.attack("T0t0");
    std::cout << RESET;
    T0t0.takeDamage(0);
    std::cout << RED ; 
    Bob.attack("T0t0");
    std::cout << RESET;
    T0t0.takeDamage(0);
    std::cout << RED ; 
    Bob.attack("T0t0");
    std::cout << RESET;
    T0t0.takeDamage(0);
    std::cout << RED ; 
    Bob.attack("T0t0");
    std::cout << RESET;
    T0t0.takeDamage(0);
    std::cout << RED ; 
    Bob.attack("T0t0");
    std::cout << RESET;
    T0t0.takeDamage(0);
    std::cout << RED ; 
    Bob.attack("T0t0");
    std::cout << RESET;
    T0t0.takeDamage(0);
    std::cout << RED ; 
    Bob.beRepaired(2);
    std::cout << RESET;
    T0t0.attack("Bob");
    std::cout << RED ; 
    Bob.attack("T0t0");
    std::cout << RESET;
    T0t0.takeDamage(0);
    std::cout << RED ; 
    Bob.attack("T0t0");
    std::cout << RESET;
    T0t0.takeDamage(0);
    std::cout << RED ; 
    Bob.attack("T0t0");
    std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << std::endl;
    std::cout << RESET;
    T0t0.attack("Bob");
    std::cout << RED ; 
    Bob.takeDamage(5);
    Bob.beRepaired(20);
    std::cout << RESET;

    T0t0.beRepaired(20);

    std::cout << "\nTesting copy constructor and assignment operator overload:" << std::endl;
    ClapTrap copy_overLord(Bob); // Copy constructor
    std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << std::endl;
    ClapTrap big_boss("BoB_Da_oVeRLoRD");
    copy_overLord = big_boss; // Assignment operator overload

    std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << std::endl;
    copy_overLord.setAttackDamage(1000);
    copy_overLord.attack("T0t0");
    T0t0.takeDamage(1000);
    T0t0.beRepaired(10);
    std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << std::endl;
    copy_overLord = T0t0;
    std::cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << std::endl;

    return 0;
}

