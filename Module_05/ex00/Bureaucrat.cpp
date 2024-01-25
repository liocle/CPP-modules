
#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name_, int grade_) : name_(name_), grade_(grade_) {
    std::cout <<  "Bureaucrat constructor called " << std::endl;
    if (grade_ < 1) 
        throw GradeTooHighException();

    if (grade_ > 150 ) {
        throw GradeTooLowException();
    }
    std::cout << getName() << " is welcome to the administrative world with a grade of: " << getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &other): name_(other.name_), grade_(other.grade_){
    std::cout << "Bureaucrat duplication sucessful" << std::endl;
}


Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called for" << getName() << std::endl;
}


Bureaucrat & Bureaucrat::operator=(Bureaucrat & other) {
    std::cout << "Bureaucrat duplication successful via operator assignment" << std::endl;
    name_ = other.name_;
    grade_ = other.grade_;
    return (*this);
}

std::ostream & operator<<(std::ostream &outputstream, Bureaucrat & a_bureaucrat){
    std::cout << a_bureaucrat.getName() << ", bureaucrat grade "  << a_bureaucrat.getGrade() << std::endl;
}

std::string     Bureaucrat::getName() {
    return (name_);
}
int             Bureaucrat::getGrade() {
    return (grade_);
}

void            Bureaucrat::incrementGrade(){
    if (grade_ == MAX_GRADE)
        throw GradeTooHighException();
    grade_--;
}

void            Bureaucrat::decrementGrade(){
    if (grade_ == MIN_GRADE)
        throw GradeTooLowException();
    grade_++;
}
