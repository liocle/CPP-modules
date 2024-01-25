#include "Bureaucrat.h"
#include <string>
#include <iostream>
#include "Colors.h"

int main(void){
    {
        std::cout << CYAN << "____________________ Bureaucrat test ____________________" << RESET << std::endl;
        try {
            std::cout << std::endl;
            std::cout << CYAN << " **** Test grade OK **** " << RESET << std::endl;
            Bureaucrat toto("toto", 42);
            std::cout << toto << std::endl;
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout << std::endl;
            std::cout << CYAN << " **** Test grade too high **** " << RESET << std::endl;
            Bureaucrat tata("tata", MAX_GRADE - 1);
            std::cout << tata << std::endl;
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout << std::endl;
            std::cout << CYAN << " **** Test grade too low **** " << RESET << std::endl;
            Bureaucrat tutu("tutu", MIN_GRADE + 1);
            std::cout << tutu << std::endl;
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }

    }
    {
        std::cout << std::endl;
        std::cout << CYAN << "____________________ Change grade test ____________________" << RESET << std::endl;
        try {
            Bureaucrat toto("toto", 42);
            std::cout << toto << std::endl;
            std::cout << std::endl;

            std::cout << CYAN << " **** Increase OK **** " << RESET << std::endl;
            toto.incrementGrade();
            std::cout << toto << std::endl;
            std::cout << std::endl;

            std::cout << CYAN << " **** Decrease OK **** " << RESET << std::endl;
            toto.decrementGrade();
            std::cout << toto << std::endl;
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    {
        try {
            std::cout << std::endl;
            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            Bureaucrat tata("tata", MAX_GRADE);
            std::cout << tata << std::endl;
            std::cout << std::endl;

            std::cout << CYAN << " **** Increase not OK **** " << RESET << std::endl;
            tata.incrementGrade();
            std::cout << tata << std::endl;
            std::cout << std::endl;
            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    {   
        try {
            std::cout << std::endl;
            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            Bureaucrat tutu("tutu", MIN_GRADE);
            std::cout << tutu << std::endl;
            std::cout << std::endl;

            std::cout << CYAN << " **** Decrease not OK **** " << RESET << std::endl;
            tutu.decrementGrade();
            std::cout << tutu << std::endl;
            std::cout << std::endl;
            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << CYAN << "____________________ Copy constructor test ____________________" << RESET << std::endl;
        try {
            Bureaucrat toto("toto", 42);
            std::cout << toto << std::endl;
            std::cout << std::endl;

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "Copy constructing a Bureaucrat (including its name)" << RESET << std::endl;
            Bureaucrat tata(toto);
            std::cout << tata << std::endl;
            std::cout << CYAN <<  "--------------------" << RESET << std::endl;

            toto.incrementGrade();
            std::cout << toto << "above is the original one" << std::endl;
            std::cout << tata << "above is the copied one not incremented" << std::endl;
            std::cout << std::endl;
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
}

