#include "Zombie.hpp"


Zombie  *zombieHorde( int horde_size , std::string name ) 
{
    Zombie  *horde = new Zombie[horde_size];

    for (int i = 0; i < horde_size; i++)
    {
        horde[i].name_this_zombie(name);
    }
    return horde;
}


