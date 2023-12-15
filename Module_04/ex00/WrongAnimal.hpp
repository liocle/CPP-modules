#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
protected:
    std::string _type;

public:
    WrongAnimal();
    WrongAnimal(WrongAnimal const & src);
    WrongAnimal & operator=(WrongAnimal const & rhs);

    virtual ~WrongAnimal();
    
    void makeSound() const;
    std::string getType() const;
};

#endif

