#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include   "ICharacter.hpp"
# define    INVENTORY_SIZE 4
# define    UNEQUIPPED_OBJ_MAX 100

class Character: public ICharacter
    {
    private:
        std::string _name;
        AMateria*   _inventory[INVENTORY_SIZE];
        AMateria*   _unequipped_objects[UNEQUIPPED_OBJ_MAX];

    public:
        Character();
        Character(std::string const &name);
        ~Character();
        Character(const Character &other);
        Character &operator = (const Character &other);

        std::string const & getName() const override;
        void equip(AMateria* m) override;
        void unequip(int idx) override;
        void use(int idx, ICharacter& target) override;
        
    };
#endif
