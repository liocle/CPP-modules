
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
    const int numberOfForms = sizeof(availableFormName) / sizeof(availableFormName[0]);
    unsigned short  form_number = numberOfForms; // Setting form number to a non existing Form  number

    for (unsigned int i = 0; i < numberOfForms; i++ ) {
        if (FormName == availableFormName[i]) {
            form_number = i;
            break;
        }
    }

    switch (form_number) {
        case 0:
            std::cout << LIGHT_BLUE << "Intern creates a PresidentialPardonForm" << RESET << std::endl;
            return (makePresidentialPardonForm(target));
        case 1:
            std::cout << LIGHT_BLUE << "Intern creates a ShrubberyCreationForm" << RESET << std::endl;
            return (makeShrubberyCreationForm(target)) ;
        case 2:
            std::cout << LIGHT_BLUE << "Intern creates a RobotomyRequestForm" << RESET << std::endl;
            return (makeRobotomyRequestForm(target));
        default:
            std::cerr << RED << "Error: Unknown form name '" << FormName << "'" << RESET << std::endl;
            return  nullptr;
    } 
 
}
