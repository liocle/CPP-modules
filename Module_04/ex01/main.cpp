#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define RED  "\033[31m"

int main() {
    {
        std::cout << BLUE;
        std::cout << "________________________________________________________________________________\n";
        std::cout << "Animal base class's makeSound() is virtual:" << std::endl;
        std::cout << "________________________________________________________________________________\n";
        std::cout << "-> Animal(), Dog() or Cat() --\n" << std::endl;
        std::cout << RESET;
        Cat     a_cat;
        std::cout << a_cat.getType() << " says: ";
        a_cat.makeSound();

        Dog     a_dog;
        std::cout << a_dog.getType() << " says: ";
        a_dog.makeSound();

        Animal  an_animal;
        std::cout << an_animal.getType() << " says: ";
        an_animal.makeSound();
        
        std::cout << BLUE ;
        std::cout << "\n-> Animal pointer to new Animal(), Dog() or Cat() --\n" << std::endl;
        std::cout << RESET;
        const Animal* meta = new Animal();
        std::cout << meta->getType() << " says: ";
        meta->makeSound();

        std::cout << std::endl;
        const Animal* j = new Dog();
        std::cout << j->getType() << " says: ";
        j->makeSound();

        std::cout <<  std::endl;
        const Animal* i = new Cat();
        std::cout << i->getType() << " says: ";
        i->makeSound(); 


        std::cout << BLUE;
        std::cout << "\n________________________________________________________________________________\n";
        std::cout << "Additional tests with WrongAnimal's makeSound attribute not being 'virtual'" << std::endl;
        std::cout << "________________________________________________________________________________\n";
        std::cout << RESET;
        const WrongAnimal* wrongJ = new WrongCat();
        std::cout << wrongJ->getType() << " says: ";
        wrongJ->makeSound(); 

        std::cout <<  std::endl;
        std::cout << "\n________________________________________________________________________________\n";
        delete meta;
        std::cout << std::endl;
        delete j;
        std::cout << std::endl;
        delete i;
        std::cout << std::endl;
        delete wrongJ;
    }

    {
        std::cout << "\n________________________________________________________________________________\n";
        std::cout << "Exercise 01 - Suggested tests" << std::endl;
        std::cout << "________________________________________________________________________________\n";
        const Animal    *j = new Dog();
        std::cout << j->getType() << " says: ";
        j->makeSound();
        const Animal    *i = new Cat();
        i->makeSound();

    }


    return 0;
}

