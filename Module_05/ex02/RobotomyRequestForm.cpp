
#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm() : AForm("A default shrubbery form", 72, 45, "Default_Robotomy"), target_("Default_Robotomy") {
    std::cout << LIGHT_GREEN << "Default RobotomyRequestForm constructor was called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm () {
    std::cout << LIGHT_GREEN << "Shrubbery destructed oke" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("A Robotomy Creation form", 72, 45, target), target_(target) {
    std::cout << LIGHT_GREEN << "RobotomyRequestForm constructor was called for target: " << target << RESET << std::endl;

}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other) : AForm(other), target_(other.target_)  {
    std::cout << LIGHT_GREEN << "Copy constructor for RobotomyRequestForm was called" << RESET << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (this->getSignature() == true) {
        if (executor.getGrade() <= this->getGradeToExecute()) {
            std::cout << RESET << executor.getName() << " executed " << getName() << std::endl;
            std::cout << RESET << "A drilling noise starts to be heard... at last " << target_ << " got finaly robotomized" << std::endl;
        }
        else 
            throw GradeTooLowException();
    }
    else
        std::cerr <<  RESET << "You want to Robotomize << " << target_ << " ? Get your Robotomy form signed first" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other)
        AForm::operator=(other);
    return (*this) ;
}
