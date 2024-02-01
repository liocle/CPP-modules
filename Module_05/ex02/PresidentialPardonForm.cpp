#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm("A Presidential Pardon form", 72, 45, "Innocent_Guy"), target_("Innocent_Guy") {
    std::cout << LIGHT_GREEN << "Default PresidentialPardonForm constructor was called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm () {
    std::cout << LIGHT_GREEN << "PresidentialPardonForm destructed oke" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("A Presidential Pardon form", 72, 45, target), target_(target) {
    std::cout << LIGHT_GREEN << "PresidentialPardonForm constructor was called for target: " << target << RESET << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other) : AForm(other), target_(other.target_)  {
    std::cout << LIGHT_GREEN << "Copy constructor for PresidentialPardonForm was called" << RESET << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (this->getSignature() == true) {
        if (executor.getGrade() <= this->getGradeToExecute()) {
            std::cout << RESET << "We have the pleasure to announce that " << target_ << " has been pardoned by the great Zaphod Beeblebrox" << std::endl;
        }
        else 
            throw GradeTooLowException();
    }
    else 
        std::cerr << RESET << "You want to pardon " << target_ << " ? Get your Presidential Pardon form signed first" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other)
        AForm::operator=(other);
    return (*this) ;
}
