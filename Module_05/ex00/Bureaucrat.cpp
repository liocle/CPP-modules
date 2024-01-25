#include "Bureaucrat.h"
#include "Colors.h"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name_(name), grade_(grade) {
    std::cout <<  GREEN << "Bureaucrat constructor called " << RESET << std::endl;
    if (grade_ < MAX_GRADE) 
        throw GradeTooHighException();

    if (grade_ > MIN_GRADE ) {
        throw GradeTooLowException();
    }
    std::cout  << getName() << " is a new bureaucrat with a grade of: " << getGrade() << RESET << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &other): name_(other.name_), grade_(other.grade_){
    std::cout << GREEN << "Bureaucrat duplication sucessful" << RESET << std::endl;
}


Bureaucrat::~Bureaucrat() {
    std::cout << GREEN << "Destructor called for " << getName() << RESET << std::endl;
}



std::ostream & operator<<(std::ostream &outputstream, Bureaucrat & a_bureaucrat){
    std::cout  << a_bureaucrat.getName() << ", bureaucrat grade "  << a_bureaucrat.getGrade() << RESET << std::endl;
    return outputstream;
}

std::string     Bureaucrat::getName() {
    return (name_);
}
int             Bureaucrat::getGrade() {
    return (grade_);
}

void            Bureaucrat::incrementGrade(){
    std::cout << GREEN << "Incrementing the grade" << RESET << std::endl;;
    if (grade_ == MAX_GRADE)
        throw GradeTooHighException();
    grade_--;
}

void            Bureaucrat::decrementGrade(){
    std::cout << GREEN << "Decrementing the grade\n";
    if (grade_ == MIN_GRADE)
        throw GradeTooLowException();
    grade_++;
}
