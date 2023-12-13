#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
    std::cout << "Animal base class's makeSound() is virtual:" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
    const Animal* meta = new Animal();
    std::cout << meta->getType() << " says: ";
    meta->makeSound();

    std::cout << "\n" << std::endl;
    const Animal* j = new Dog();
    std::cout << j->getType() << " says: ";
    j->makeSound();

    std::cout << "\n" << std::endl;
    const Animal* i = new Cat();
    std::cout << i->getType() << " says: ";
    i->makeSound(); 


    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
    std::cout << "Additional tests with WrongAnimal's makeSound attribute not being 'virtual'" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
    const WrongAnimal* wrongJ = new WrongCat();
    std::cout << wrongJ->getType() << " says: ";
    wrongJ->makeSound(); 

    std::cout <<  std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
    delete meta;
    std::cout << std::endl;
    delete j;
    std::cout << std::endl;
    delete i;
    std::cout << std::endl;
    delete wrongJ;

    return 0;
}

