#include "Form.h"
#include "Colors.h"
#include "Bureaucrat.h"
#include <iostream>

Form::Form() : name_("a_form"), signed_flag_(false), grade_required_to_sign_form_(MIN_GRADE_TO_SIGN), grade_required_to_execute_form_(MIN_GRADE_TO_EXECUTE) {
    std::cout << YELLOW << "Constructor called for " << name_ << " with default values: " << std::endl;
    std::cout << *this << RESET;
}

Form::~Form() {
    std::cout << YELLOW << "Destructor called for " << name_ << RESET << std::endl;
};

Form::Form(const std::string name, const unsigned int grade_to_sign, const unsigned int grade_to_execute) :
    name_(name), signed_flag_(false), grade_required_to_sign_form_(grade_to_sign), grade_required_to_execute_form_(grade_to_execute){
    std::cout << "Constructor called for " << name_ << " with provided values: " << RESET << std::endl;
    std::cout << *this;
    if (grade_required_to_sign_form_ > MIN_GRADE || grade_required_to_execute_form_ > MIN_GRADE)
        throw GradeTooLowException();
    if (grade_required_to_sign_form_ < MAX_GRADE || grade_required_to_execute_form_ < MAX_GRADE)
        throw GradeTooHighException();
};

Form::Form(const Form &other) : name_(other.name_), signed_flag_(false), grade_required_to_sign_form_(other.grade_required_to_sign_form_), grade_required_to_execute_form_(other.grade_required_to_execute_form_) {
    std::cout << YELLOW <<   "Copy constructor called for " << name_ << " with copied form values: " << RESET << std::endl;
    std::cout << *this;
    if (grade_required_to_sign_form_ > MIN_GRADE || grade_required_to_execute_form_ > MIN_GRADE)
        throw GradeTooLowException();
    if (grade_required_to_sign_form_ < MAX_GRADE || grade_required_to_execute_form_ < MAX_GRADE)
        throw GradeTooHighException();
};

Form & Form::operator=(const Form &other){
    signed_flag_ = other.signed_flag_;
    return (*this);
};

const std::string     Form::getName() const {
    return (name_);
};

void                  Form::beSigned(Bureaucrat & a_bureaucrat) {
    if (a_bureaucrat.getGrade() > getGradeToSign() ) {
        std::cout << RED << *this;
        throw Form::GradeTooLowException();
    }
    signed_flag_ = true;
    std::cout << *this << RESET << std::endl;
};

bool                  Form::getSignature() const {
    return (signed_flag_);
};

unsigned int    Form::getGradeToSign() const {
    return (grade_required_to_sign_form_);
};

unsigned int    Form::getGradeToExecute() const {
    return (grade_required_to_execute_form_);
};

std::ostream &operator<<(std::ostream &outputstream, const Form &form){

    outputstream << "Form name: " << form.getName() << std::endl
        << "Signed: " << (form.getSignature() ? "true" : "false") << std::endl
        << "Grade required to sign form: " << form.getGradeToSign() << std::endl
        << "Grade required to execute form: " << form.getGradeToExecute() << std::endl;
    return (outputstream);
}

