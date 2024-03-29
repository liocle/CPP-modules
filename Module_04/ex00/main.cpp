#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define RESET "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RED  "\033[31m"

/**
  * @brief Polymorphism is demonstrated through the use of pointers to base class objects.
  */
int main() {
    {
        std::cout << BLUE;
        std::cout << "________________________________________________________________________________\n";
        std::cout << "Exercise00: Use of virtual makeSound() on base and derived class objects through pointers:" << std::endl;
        std::cout << "________________________________________________________________________________\n";
        std::cout << CYAN;
        std::cout << "-> Animal(), Dog() or Cat():\n";
        std::cout << RESET;

        // Creating objects of the base class.
        Animal  an_animal;
        std::cout << an_animal.getType() << " says: ";
        an_animal.makeSound();                          

        // Creating derived Dog objects.
        std::cout << std::endl;
        Dog     a_dog;
        std::cout << a_dog.getType() << " says: ";
        a_dog.makeSound();                              

        // Creating derived Cat objects.
        std::cout << std::endl;
        Cat     a_cat;
        std::cout << a_cat.getType() << " says: ";
        a_cat.makeSound();                              


        
        std::cout << CYAN;
        std::cout << "\n-> Animal pointer to new Animal(), Dog() or Cat():\n";
        std::cout << RESET;
        const Animal* meta = new Animal();
        std::cout << meta->getType() << " says: ";
        meta->makeSound();                              // uses base class makeSound()

        std::cout << std::endl;
        const Animal* j = new Dog();
        std::cout << j->getType() << " says: ";
        j->makeSound();                                 // uses Dog class implementation of makeSound()

        std::cout <<  std::endl;
        const Animal* i = new Cat();
        std::cout << i->getType() << " says: ";
        i->makeSound();                                 // uses Cat class implementation of makeSound()


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
        std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";
        delete meta;
        std::cout << std::endl;
        delete j;
        std::cout << std::endl;
        delete i;
        std::cout << std::endl;
        delete wrongJ;
    }
    return 0;

}
