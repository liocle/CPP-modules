
#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name_, int grade_) throw (): name_(name_), grade_(grade_) {
        if (grade_ < 1) 
            throw GradeTooHighException();

        if (grade_ > 150 ) 
            throw GradeTooLowException();
}


