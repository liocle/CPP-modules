#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

public:
    Zombie();
    Zombie(std::string zombieName);
    ~Zombie(void);
    void announce(void);

private:
    std::string _name;
};
#endif // !ZOMBIE_HPP
