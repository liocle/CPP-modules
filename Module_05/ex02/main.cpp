#include "Bureaucrat.h"
#include <string>
#include <iostream>
#include "Colors.h"

int main(void){
    // {
    //     std::cout << CYAN << "____________________ Bureaucrat test ____________________" << RESET << std::endl;
    //     try {
    //         std::cout << std::endl;
    //         std::cout << CYAN << " **** Test grade OK **** " << RESET << std::endl;
    //         Bureaucrat toto; 
    //     } catch (std::exception &e) {
    //         std::cerr << RED << e.what() << RESET << std::endl;
    //     }
    //     try {
    //         std::cout << std::endl;
    //         std::cout << CYAN << " **** Test grade too high **** " << RESET << std::endl;
    //         Bureaucrat tata("tata", MAX_GRADE - 1);
    //         std::cout << tata << std::endl;
    //     } catch (std::exception &e) {
    //         std::cerr << RED << e.what() << RESET << std::endl;
    //     }
    //     try {
    //         std::cout << std::endl;
    //         std::cout << CYAN << " **** Test grade too low **** " << RESET << std::endl;
    //         Bureaucrat tutu("tutu", MIN_GRADE + 1);
    //         std::cout << tutu << std::endl;
    //     } catch (std::exception &e) {
    //         std::cerr << RED << e.what() << RESET << std::endl;
    //     }

    // }
    // {
    //     std::cout << std::endl;
    //     std::cout << CYAN << "____________________ Change grade test ____________________" << RESET << std::endl;
    //     try {
    //         Bureaucrat toto("toto", 42);
    //         std::cout << std::endl;

    //         std::cout << CYAN << " **** Increase OK **** " << RESET << std::endl;
    //         toto.incrementGrade();
    //         std::cout << toto << std::endl;
    //         std::cout << std::endl;

    //         std::cout << CYAN << " **** Decrease OK **** " << RESET << std::endl;
    //         toto.decrementGrade();
    //         std::cout << toto << std::endl;
    //     } catch (std::exception &e) {
    //         std::cerr << RED << e.what() << RESET << std::endl;
    //     }
    // }
    // {
    //     try {
    //         std::cout << std::endl;
    //         std::cout << CYAN <<  "--------------------" << RESET << std::endl;
    //         Bureaucrat tata("tata", MAX_GRADE);
    //         std::cout << std::endl;

    //         std::cout << CYAN << " **** Increase not OK **** " << RESET << std::endl;
    //         tata.incrementGrade();
    //         std::cout << tata << std::endl;
    //         std::cout << std::endl;
    //         std::cout << CYAN <<  "--------------------" << RESET << std::endl;
    //     } catch (std::exception &e) {
    //         std::cerr << RED << e.what() << RESET << std::endl;
    //     }
    // }
    // {   
    //     try {
    //         std::cout << std::endl;
    //         std::cout << CYAN <<  "--------------------" << RESET << std::endl;
    //         Bureaucrat tutu("tutu", MIN_GRADE);
    //         std::cout << std::endl;

    //         std::cout << CYAN << " **** Decrease not OK **** " << RESET << std::endl;
    //         tutu.decrementGrade();
    //         std::cout << tutu << std::endl;
    //         std::cout << std::endl;
    //         std::cout << CYAN <<  "--------------------" << RESET << std::endl;
    //     } catch (std::exception &e) {
    //         std::cerr << RED << e.what() << RESET << std::endl;
    //     }
    // }
    // {
    //     std::cout << std::endl;
    //     std::cout << CYAN << "____________________ Copy constructor test ____________________" << RESET << std::endl;
    //     try {
    //         Bureaucrat toto("toto", 42);
    //         std::cout << std::endl;

    //         std::cout << CYAN <<  "--------------------" << RESET << std::endl;
    //         std::cout << CYAN <<  "Copy constructing a Bureaucrat" << RESET << std::endl;
    //         Bureaucrat tata(toto);
    //         std::cout << std::endl;

    //         std::cout << CYAN <<  "--------------------" << RESET << std::endl;
    //         std::cout << CYAN <<  "Assigning a bureaucrat to another one" << RESET << std::endl;
    //         std::cout << CYAN <<  "Only the grade can be copied" << RESET << std::endl;
    //         Bureaucrat tutu;
    //         Bureaucrat another("High_ranked_bureaucrat", 1);
    //         
    //         std::cout << std::endl;
    //         tutu = another;
    //         std::cout << std::endl;

    //     } catch (std::exception &e) {
    //         std::cerr << RED << e.what() << RESET << std::endl;
    //     }
    // }
    {
        std::cout << std::endl;
        std::cout << CYAN << "____________________ Form test ____________________" << RESET << std::endl;
        try {
            std::cout << CYAN <<  "2 bureaucrats are at work, a high rank and toto" << RESET << std::endl;
            Bureaucrat toto("Toto", 42);
            Bureaucrat high_ranked_bureaucrat("High_ranked_bureaucrat", 1);
            std::cout << std::endl;

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "A default form appears on the desk" << RESET << std::endl;
            Form a_form;

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "Toto tries to sign with a too low grade" << RESET << std::endl;
            toto.signForm(a_form);
            std::cout << std::endl;

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "A High_ranked_bureaucrat can sign it" << RESET << std::endl;
            high_ranked_bureaucrat.signForm(a_form);
            std::cout << std::endl;

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "A High_ranked_bureaucrat can't sign it twice" << RESET << std::endl;
            high_ranked_bureaucrat.signForm(a_form);
            std::cout << std::endl;
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
        try {
            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "A special form, properly set, appears on the desk" << RESET << std::endl;
            Form form("Pretty secure form", 10, 20);
        } catch (std::exception &e){
            std::cerr << RED << e.what() << RESET << std::endl;
        }
        try {
            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "A special form, with a too high grade to sign, appears on the desk" << RESET << std::endl;
            Form form("Pretty secure form", 0, 20);
        } catch (std::exception &e){
            std::cerr << RED << e.what() << RESET << std::endl;
        }
        try {
            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "A special form, with a too low grade to sign, appears on the desk" << RESET << std::endl;
            Form form("Pretty secure form", 10000, 20);
        } catch (std::exception &e){
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }

}

