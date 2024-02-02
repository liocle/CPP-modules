
#include "Intern.h"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

AForm * Intern::makePresidentialPardonForm(const std::string target) {
    return (new PresidentialPardonForm(target));
}

AForm * Intern::makeShrubberyCreationForm(const std::string target) {
    return (new ShrubberyCreationForm(target));
}

AForm * Intern::makeRobotomyRequestForm(const std::string target) {
    return (new RobotomyRequestForm(target));
}


AForm * Intern::makeForm(std::string FormName, const std::string target) {


    std::string availableFormName[] = {
        "PresidentialPardonForm",   // Form 0
        "ShrubberyCreationForm",    // Form 1
        "RobotomyRequestForm"       // Form 2
    };
    const int AmountOfForms = sizeof(availableFormName) / sizeof(availableFormName[0]);
    unsigned short  form_number;

    for (unsigned int i = 0; i < AmountOfForms; i++ ) {
        if (FormName == availableFormName[i]) {
            form_number = i;
        }
    }

    switch (form_number) {
        case 0:
            std::cout << LIGHT_BLUE << "Intern creates a PresidentialPardonForm" << RESET << std::endl;
            return (makePresidentialPardonForm(target));
        case 1:
            std::cout << LIGHT_BLUE << "Intern creates a ShrubberyCreationForm" << RESET << std::endl;
            return (makeShrubberyCreationForm(target)) ;
            break;
        case 2:
            std::cout << LIGHT_BLUE << "Intern creates a RobotomyRequestForm" << RESET << std::endl;
            return (makeRobotomyRequestForm(target));
        default:
            std::cerr << RED << "Error: Unknown form name '" << FormName << "'" << RESET << std::endl;
            return  nullptr;
    } 
 
}
