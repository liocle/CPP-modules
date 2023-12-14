#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RED  "\033[31m"

int main() {
    {
        std::cout << BLUE;
        std::cout << "________________________________________________________________________________\n";
        std::cout << "Exercise00: Animal base class's makeSound() is virtual:" << std::endl;
        std::cout << "________________________________________________________________________________\n";
        std::cout << CYAN;
        std::cout << "-> Animal(), Dog() or Cat():\n";
        std::cout << RESET;

        Animal  an_animal;
        std::cout << an_animal.getType() << " says: ";
        an_animal.makeSound();

        std::cout << std::endl;
        Dog     a_dog;
        std::cout << a_dog.getType() << " says: ";
        a_dog.makeSound();

        std::cout << std::endl;
        Cat     a_cat;
        std::cout << a_cat.getType() << " says: ";
        a_cat.makeSound();


        
        std::cout << CYAN;
        std::cout << "\n-> Animal pointer to new Animal(), Dog() or Cat():\n";
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
        std::cout << "Exercise00: Additional tests with WrongAnimal's makeSound attribute not being 'virtual'" << std::endl;
        std::cout << "________________________________________________________________________________\n";

        std::cout << CYAN;
        std::cout << "\n-> WrongAnimal(), WrongCat():\n";
        std::cout << RESET;
        WrongAnimal a_wrong_animal;
        std::cout << a_wrong_animal.getType() << " says: ";
        a_wrong_animal.makeSound();

        std::cout <<  std::endl;
        WrongCat a_wrong_cat;
        std::cout << a_wrong_cat.getType() << " says: ";
        a_wrong_cat.makeSound();


        std::cout << CYAN;
        std::cout << "\n-> WrongAnimal pointer to WrongCat:\n";
        std::cout << RESET;
        const WrongAnimal* wrongJ = new WrongCat();
        std::cout << wrongJ->getType() << " says: ";
        wrongJ->makeSound(); 

        std::cout <<  std::endl;
        std::cout << BLUE;
        std::cout << "\n________________________________________________________________________________\n";
        std::cout << RESET;
        delete meta;
        std::cout << std::endl;
        delete j;
        std::cout << std::endl;
        delete i;
        std::cout << std::endl;
        delete wrongJ;
    }

    {
        std::cout << BLUE;
        std::cout << "\n________________________________________________________________________________\n";
        std::cout << "Exercise 01: Suggested tests" << std::endl;
        std::cout << "________________________________________________________________________________\n";
        std::cout << RESET;
        const Animal    *j = new Dog();
        std::cout << j->getType() << " says: ";
        j->makeSound();

        std::cout << std::endl;
        const Animal    *i = new Cat();
        i->makeSound();

        std::cout << std::endl;
        int     size = 10;
        Animal  *animal_array[size];

        for (int i = 0; i < size; i++)
        {
            if (i%2 == 0)
            {
                animal_array[i] = new Cat;
            }
            else
               animal_array[i] = new Dog;
             std::cout << "Instantiating animal #" << i+1 << " of type: " << animal_array[i]->getType() << std::endl;
        }

        std::cout << BLUE;
        std::cout << "\n________________________________________________________________________________\n";
        std::cout << RESET;
        for (int i = 0; i < size; i++)
        {
            delete animal_array[i];
             std::cout << "Animal #" << i+1 << " is gone\n";
        }

 

    }


    return 0;
}

