#include "Bureaucrat.h"
#include "Colors.h"

Bureaucrat::Bureaucrat() : name_("a_bureaucrat"), grade_(42) {
    std::cout <<  GREEN << "Bureaucrat constructor called " << RESET << std::endl;
    std::cout << *this << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name_(name), grade_(grade) {
    std::cout <<  GREEN << "Bureaucrat constructor called " << RESET << std::endl;
    if (grade_ < MAX_GRADE) 
        throw GradeTooHighException();

    if (grade_ > MIN_GRADE ) {
        throw GradeTooLowException();
    }
    std::cout << *this << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &other): name_(other.name_), grade_(other.grade_){
    std::cout << GREEN << "Bureaucrat duplication sucessful" << RESET << std::endl;
    std::cout << *this << " at location " << this << std::endl;
    std::cout << other << " at location " << &other << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other) {
    std::cout << "Assigning " << other << RESET << std::endl;
    if (this != &other) {
        grade_ = other.grade_;
    }
    std::cout << *this << std::endl;
    std::cout << other << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    std::cout << GREEN << "Destructor called for " << getName() << RESET << std::endl;
}

std::string     Bureaucrat::getName() const {
    return (name_);
}

unsigned int    Bureaucrat::getGrade() const {
    return (grade_);
}

void            Bureaucrat::incrementGrade(){
    std::cout << GREEN << "Incrementing the grade" << RESET << std::endl;;
    if (grade_ == MAX_GRADE)
        throw GradeTooHighException();
    grade_--;
}

void            Bureaucrat::decrementGrade(){
    std::cout << GREEN << "Decrementing the grade" << RESET << std::endl;
    if (grade_ == MIN_GRADE)
        throw GradeTooLowException();
    grade_++;
}


void            Bureaucrat::signForm(AForm &form) {
    if (form.getSignature() == true) {
        std::cout << name_ << " cannot sign twice the same form named: " << form.getName() << std::endl;
    }
    else {
        try {
            form.beSigned(*this);
        } catch (AForm::GradeTooLowException &e) { 
            std::cout << RED << std::endl << "-> "<< e.what() << " <-" << RESET << std::endl;
            std::cout <<  name_ << " does not have the permission to sign with a bureaucrat's grade of: " << this->grade_ << std::endl;
        }
    }
}
        

std::ostream & operator<<(std::ostream &outputstream, const Bureaucrat & a_bureaucrat){
    outputstream  << a_bureaucrat.getName() << ", bureaucrat grade "  << a_bureaucrat.getGrade() << RESET;
    return outputstream;
}

