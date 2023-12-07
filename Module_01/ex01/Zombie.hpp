#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define HORDE_SIZE 5
#include <iostream>
#include <string>

class Zombie {

public:
    Zombie();
    Zombie(std::string zombieName);
    ~Zombie(void);
    void announce(int horde_size);
    void name_this_zombie( std::string name_them);

private:
    std::string _name;
};
#endif // !ZOMBIE_HP 
