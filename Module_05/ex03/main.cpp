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
            std::cout << CYAN <<  "The Intern attmps to create a ShrubberyCreationForm" << RESET << std::endl;
            AForm *a_form = another_intern.makeForm("ShrubberyCreationForm", "Home_Sweet_home");

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "High_ranked_bureaucrat signs the form" << RESET << std::endl;
            high_ranked_bureaucrat.signForm(*a_form);
            std::cout << std::endl;

            std::cout << CYAN << "---------------------" << RESET << std::endl;
            std::cout << CYAN << "High_ranked_bureaucrat executes it" << std::endl;
            a_form->execute(high_ranked_bureaucrat);

        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << RED << "______________________________________________________________________" << RESET << std::endl;
        std::cout << std::endl;
        std::cout << CYAN << "____________________ Robotomy Form test ____________________" << RESET << std::endl;
        try {
            std::cout << CYAN <<  "2 bureaucrats are at work, a high rank and toto" << RESET << std::endl;
            Bureaucrat toto("Toto", 42);
            Bureaucrat tata("Tata", 150);
            Bureaucrat high_ranked_bureaucrat("High_ranked_bureaucrat", 1);
            std::cout << std::endl;

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "A default Robotomy form appears on the desk" << RESET << std::endl;
            RobotomyRequestForm a_Robotomy_form("Toto");
            std::cout << std::endl;

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "Toto tries to sign with a good enough grade" << RESET << std::endl;
            toto.signForm(a_Robotomy_form);
            std::cout << std::endl;

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "A High_ranked_bureaucrat tries to sign the already signed form" << RESET << std::endl;
            high_ranked_bureaucrat.signForm(a_Robotomy_form);
            std::cout << std::endl;

            std::cout << CYAN << "---------------------" << RESET << std::endl;
            std::cout << CYAN << "High_ranked_bureaucrat wants to robotomize Toto" << std::endl;
            a_Robotomy_form.execute(high_ranked_bureaucrat);
            std::cout << std::endl;

            std::cout << CYAN << "---------------------" << RESET << std::endl;
            std::cout << CYAN << "Toto tries to execute the Form" << std::endl;
            a_Robotomy_form.execute(tata);
            std::cout << CYAN << "---------------------" << RESET << std::endl;

        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << RED << "______________________________________________________________________" << RESET << std::endl;
        std::cout << std::endl;
        std::cout << CYAN << "____________________ PresidentialPardon Form test ____________________" << RESET << std::endl;
        try {
            std::cout << CYAN <<  "2 bureaucrats are at work, a high rank and toto" << RESET << std::endl;
            Bureaucrat toto("Toto", 150);
            Bureaucrat high_ranked_bureaucrat("High_ranked_bureaucrat", 1);
            std::cout << std::endl;

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "A default Presidential Pardon form appears on the desk" << RESET << std::endl;
            PresidentialPardonForm a_Presidential_Pardon_Form("An_innocent");

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "Toto tries to sign with a too low grade" << RESET << std::endl;
            toto.signForm(a_Presidential_Pardon_Form);
            std::cout << std::endl;

            std::cout << CYAN << "---------------------" << RESET << std::endl;
            std::cout << CYAN << "High_ranked_bureaucrat tries to execute the unsigned Form" << std::endl;
            a_Presidential_Pardon_Form.execute(high_ranked_bureaucrat);

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "A High_ranked_bureaucrat signs it" << RESET << std::endl;
            high_ranked_bureaucrat.signForm(a_Presidential_Pardon_Form);
            std::cout << std::endl;

            std::cout << CYAN << "---------------------" << RESET << std::endl;
            std::cout << CYAN << "High_ranked_bureaucrat tries to execute it again now that it is signed" << std::endl;
            a_Presidential_Pardon_Form.execute(high_ranked_bureaucrat);

            std::cout << CYAN <<  "--------------------" << RESET << std::endl;
            std::cout << CYAN <<  "It can't sign it twice" << RESET << std::endl;
            high_ranked_bureaucrat.signForm(a_Presidential_Pardon_Form);
            std::cout << std::endl;

            std::cout << CYAN << "---------------------" << RESET << std::endl;
            std::cout << CYAN << "Toto tries to execute the Form lol" << std::endl;
            a_Presidential_Pardon_Form.execute(toto);
            std::cout << CYAN << "---------------------" << RESET << std::endl;

        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
}

