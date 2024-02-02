#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <string>
#include <iostream>
#include "Colors.h"
#include "Intern.h"

int main(void){
    {
        std::cout << std::endl;
        std::cout << CYAN << "____________________ Shrubbery Form test ____________________" << RESET << std::endl;
        try {
            std::cout << CYAN <<  "An Intern makes oneself helpful" << RESET << std::endl;
            Intern another_intern;
            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            Bureaucrat high_ranked_bureaucrat("High_ranked_bureaucrat", 1);
            std::cout << std::endl;

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "The Intern atempts to create a ShrubberyCreationForm" << RESET << std::endl;
            AForm *a_form = another_intern.makeForm("ShrubberyCreationForm", "Home_Sweet_home");

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "High_ranked_bureaucrat signs the form" << RESET << std::endl;
            high_ranked_bureaucrat.signForm(*a_form);
            std::cout << std::endl;

            std::cout << CYAN << "---------------------" << RESET << std::endl;
            std::cout << CYAN << "High_ranked_bureaucrat executes it" << std::endl;
            a_form->execute(high_ranked_bureaucrat);
            delete a_form;

        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << CYAN << "____________________ Presidential Form test ____________________" << RESET << std::endl;
        try {
            std::cout << CYAN <<  "An Intern makes oneself helpful" << RESET << std::endl;
            Intern another_intern;
            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            Bureaucrat high_ranked_bureaucrat("High_ranked_bureaucrat", 1);
            std::cout << std::endl;

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "The Intern attempts to create a PresidentialPardonForm" << RESET << std::endl;
            AForm *a_form = another_intern.makeForm("PresidentialPardonForm", "Innocent");

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "High_ranked_bureaucrat signs the form" << RESET << std::endl;
            high_ranked_bureaucrat.signForm(*a_form);
            std::cout << std::endl;

            std::cout << CYAN << "---------------------" << RESET << std::endl;
            std::cout << CYAN << "High_ranked_bureaucrat executes it" << std::endl;
            a_form->execute(high_ranked_bureaucrat);
            
            delete a_form;

        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << CYAN << "____________________ Robotomy Form test ____________________" << RESET << std::endl;
        try {
            std::cout << CYAN <<  "An Intern makes oneself helpful" << RESET << std::endl;
            Intern another_intern;
            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            Bureaucrat high_ranked_bureaucrat("High_ranked_bureaucrat", 1);
            std::cout << std::endl;

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "The Intern atempts to create a RobotomyRequestForm" << RESET << std::endl;
            AForm *a_form = another_intern.makeForm("RobotomyRequestForm", "Bender");

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "High_ranked_bureaucrat signs the form" << RESET << std::endl;
            high_ranked_bureaucrat.signForm(*a_form);
            std::cout << std::endl;

            std::cout << CYAN << "---------------------" << RESET << std::endl;
            std::cout << CYAN << "High_ranked_bureaucrat executes it" << std::endl;
            a_form->execute(high_ranked_bureaucrat);

            delete a_form;
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << CYAN << "____________________ Non existing Form test ____________________" << RESET << std::endl;
        try {
            std::cout << CYAN <<  "An Intern commes up" << RESET << std::endl;
            Intern another_intern;

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "The Intern is distracted and mispells shrubbery" << RESET << std::endl;
            AForm *a_form = another_intern.makeForm("ShruberyCreationForm", "Home_Sweet_home");

            delete a_form;
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
}

