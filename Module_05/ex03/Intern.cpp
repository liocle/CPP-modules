
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
    AForm *formCreator[] = {
        makePresidentialPardonForm(target),
        makeShrubberyCreationForm(target),
        makeRobotomyRequestForm(target)
    }; 

    const int AmountOfForms = sizeof(formCreator) / sizeof(formCreator[0]);

    std::string availableFormName[] = {
        "PresidentialPardonForm",
        "ShrubberyCreationForm",
        "RobotomyRequestForm"
    };

    for (unsigned int i = 0; i < (sizeof(formCreator) / sizeof(formCreator[0])); i++ ) {
        if (FormName == availableFormName[i]) {
            return (formCreator[i]);
        }
    }

    std::cerr << RED << "Error: Unknown form name '" << FormName << "'" << RESET << std::endl;
 
    return  nullptr;
}
