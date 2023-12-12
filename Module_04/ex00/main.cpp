#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" << std::endl;
    std::cout << "//-> const Animal* meta = new Animal();\n";
    const Animal* meta = new Animal();
    std::cout << "//-> std::cout << meta->getType() << \" says:\"\n";
    std::cout << meta->getType() << " says: ";
    meta->makeSound();

    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" << std::endl;
    std::cout << "//-> const Animal* j = new Dog();\n";
    const Animal* j = new Dog();
    std::cout << "//-> std::cout << j->getType() << \" says:\"\n";
    std::cout << j->getType() << " says: ";
    j->makeSound();

    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" << std::endl;
    std::cout << "//-> const Animal* i = new Cat() -- \n";
    const Animal* i = new Cat();
    std::cout << "//-> std::cout << i->getType() << \" says:\"\n";
    std::cout << i->getType() << " says: ";
    i->makeSound(); // will output the cat sound!

    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" << std::endl;


    // Additional tests
    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" << std::endl;
    std::cout << "//-> const WrongAnimal* wrongJ = new WrongCat()";
    const WrongAnimal* wrongJ = new WrongCat();
    std::cout << "//-> std::cout << wrongJ->getType() << \" says:\"\n";
    std::cout << wrongJ->getType() << " says: ";
    wrongJ->makeSound(); // will output the WrongCat sound!

    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" << std::endl;
    std::cout << "//-> delete meta; //aka Animal\n";
    delete meta;
    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" << std::endl;
    std::cout << "//-> delete j; //aka Dog\n";
    delete j;
    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" << std::endl;
    std::cout << "//-> delete i; //aka Cat\n";
    delete i;
    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" << std::endl;
    std::cout << "//-> delete wrongJ; //aka WrongCat\n";
    delete wrongJ;

    return 0;
}

