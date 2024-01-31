
#include "RobotomyRequestForm.h"
#include "Colors.h"

RobotomyRequestForm::RobotomyRequestForm() : AForm("A default shrubbery form", 72, 45, "default location") {
    std::cout << LIGHT_GREEN << "Default RobotomyRequestForm constructor was called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm () {
    std::cout << LIGHT_GREEN << "Shrubbery destructed oke" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("A Shrubbery form", 72, 45, target) {
    std::cout << LIGHT_GREEN << "RobotomyRequestForm constructor was called for target: " << target << RESET << std::endl;

}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other) : AForm(other)  {
    std::cout << LIGHT_GREEN << "Copy constructor for RobotomyRequestForm was called" << RESET << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (this->getSignature() == true) {
        if (executor.getGrade() <= this->getGradeToExecute()) {
            std::cout << "A drilling noise starts to be heard... at last " << target_ << " got finaly robotomized" << std::endl;
        }
        else 
            throw GradeTooLowException();
    }
    std::cerr << "You want to Robotomize << " << target_ << " ? Get your Robotomy form signed first" << std::endl;
}
