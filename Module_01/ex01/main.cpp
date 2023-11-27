#include <iostream>
#include "Zombie.hpp"

Zombie  *zombieHorde( int N, std::string heapy_horde );


int main (void) {

    std::string zombie_name = "heapy_zombie";

    Zombie *horde = zombieHorde(HORDE_SIZE, zombie_name);
    for (int i = 0; i < HORDE_SIZE; i++)
    {
        horde[i].announce(i + 1);
    }
    delete[] horde;

    return (0);
} 

