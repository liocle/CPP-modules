#include "ClapTrap.hpp"

int main() {
    std::cout << "Testing constructors and basic actions:" << std::endl;
    ClapTrap T0t0; // Default constructor
    ClapTrap Bob("Bob"); // Parameterized constructor

    T0t0.attack("Bob");
    Bob.takeDamage(0);
    Bob.attack("T0t0");
    T0t0.takeDamage(0);
    T0t0.setAttackDamage(5); //increase attack damage
    T0t0.attack("Bob");
    Bob.takeDamage(5);
    Bob.attack("T0t0");
    T0t0.takeDamage(0);
    Bob.attack("T0t0");
    T0t0.takeDamage(0);
    Bob.attack("T0t0");
    T0t0.takeDamage(0);
    Bob.attack("T0t0");
    T0t0.takeDamage(0);
    Bob.attack("T0t0");
    T0t0.takeDamage(0);
    Bob.attack("T0t0");
    T0t0.takeDamage(0);
    Bob.beRepaired(2);
    T0t0.attack("Bob");
    Bob.attack("T0t0");
    T0t0.takeDamage(0);
    Bob.attack("T0t0");
    T0t0.takeDamage(0);
    Bob.attack("T0t0");
    T0t0.attack("Bob");
    Bob.takeDamage(5);
    

    T0t0.beRepaired(20);

    std::cout << "\nTesting copy constructor and assignment operator overload:" << std::endl;
    ClapTrap copy_overLord(Bob); // Copy constructor
    copy_overLord = T0t0; // Assignment operator overload

    copy_overLord.attack("Target3");
    copy_overLord.takeDamage(7);
    copy_overLord.beRepaired(6);
    T0t0.setAttackDamage(5); // Increase attack damage to 5
    T0t0.attack("copy_overlord"); // Now, this will use the updated attack damage
    copy_overLord.takeDamage(5);
    copy_overLord.beRepaired(1000);
    T0t0.attack("copy_overlord");
    copy_overLord.takeDamage(5);
    T0t0.attack("copy_overlord");
    copy_overLord.takeDamage(5);
    T0t0.attack("copy_overlord");
    copy_overLord.takeDamage(5);
    T0t0.attack("copy_overlord");
    copy_overLord.takeDamage(5);
    T0t0.attack("copy_overlord");
    copy_overLord.setAttackDamage(1000);
    copy_overLord.attack("T0t0");
    T0t0.takeDamage(1000);
    T0t0.beRepaired(10);

    return 0;
}

