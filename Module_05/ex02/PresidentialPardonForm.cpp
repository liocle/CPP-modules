#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm("A default shrubbery form", 72, 45, "default location") {
    std::cout << LIGHT_GREEN << "Default PresidentialPardonForm constructor was called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm () {
    std::cout << LIGHT_GREEN << "Shrubbery destructed oke" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("A Shrubbery form", 72, 45, target) {
    std::cout << LIGHT_GREEN << "PresidentialPardonForm constructor was called for target: " << target << RESET << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other) : AForm(other)  {
    std::cout << LIGHT_GREEN << "Copy constructor for PresidentialPardonForm was called" << RESET << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (this->getSignature() == true) {
        if (executor.getGrade() <= this->getGradeToExecute()) {
            std::cout << "We have the pleasure to announce that " << target_ << " has been pardoned  by the great Zaphod Beeblebrox" << std::endl;
        }
        else 
            throw GradeTooLowException();
    }
    std::cerr << "You want to Robotomize << " << target_ << " ? Get your Robotomy form signed first" << std::endl;
}
