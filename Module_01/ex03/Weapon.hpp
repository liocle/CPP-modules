
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {

public:
    Weapon(void);
    Weapon(std::string weapon_type);
    ~Weapon(void);

    void                setType(std::string weapon_type);
    const std::string   &getType(void);
    
private:
    std::string type;    
};
#endif 

