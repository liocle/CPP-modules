#include "AForm.h"
#include "Colors.h"
#include "Bureaucrat.h"
#include <iostream>

AForm::AForm() : name_("a_form"),  signed_flag_(false), grade_required_to_sign_form_(MIN_GRADE_TO_SIGN), grade_required_to_execute_form_(MIN_GRADE_TO_EXECUTE), target_("default target") {
    std::cout << YELLOW << "Constructor called for " << name_ << " with default values: " << std::endl;
    std::cout << *this << RESET;
}

AForm::~AForm() {
    std::cout << YELLOW << "Destructor called for " << name_ << RESET << std::endl;
};

AForm::AForm(const std::string name, const unsigned int grade_to_sign, const unsigned int grade_to_execute, const std::string target) :
    name_(name), signed_flag_(false),  grade_required_to_sign_form_(grade_to_sign), grade_required_to_execute_form_(grade_to_execute), target_(target) {
    std::cout << "Constructor called for " << name_ << " with provided values: " << RESET << std::endl;
    std::cout << *this;
    if (grade_required_to_sign_form_ > MIN_GRADE || grade_required_to_execute_form_ > MIN_GRADE)
        throw GradeTooLowException();
    if (grade_required_to_sign_form_ < MAX_GRADE || grade_required_to_execute_form_ < MAX_GRADE)
        throw GradeTooHighException();
};

AForm::AForm(const AForm &other) : name_(other.name_), signed_flag_(false), grade_required_to_sign_form_(other.grade_required_to_sign_form_), grade_required_to_execute_form_(other.grade_required_to_execute_form_), target_(other.target_) {
    std::cout << YELLOW <<   "Copy constructor called for " << name_ << " with copied form values: " << RESET << std::endl;
    std::cout << *this;
    if (grade_required_to_sign_form_ > MIN_GRADE || grade_required_to_execute_form_ > MIN_GRADE)
        throw GradeTooLowException();
    if (grade_required_to_sign_form_ < MAX_GRADE || grade_required_to_execute_form_ < MAX_GRADE)
        throw GradeTooHighException();
};

AForm & AForm::operator=(const AForm &other){
    if (this != &other)
        signed_flag_ = other.signed_flag_;
    return (*this);
};

const std::string     AForm::getName() const {
    return (name_);
};

void                  AForm::beSigned(Bureaucrat & a_bureaucrat) {
    if (a_bureaucrat.getGrade() > getGradeToSign() ) {
        std::cout << RED << *this;
        throw AForm::GradeTooLowException();
    }
    signed_flag_ = true;
    std::cout << *this << RESET << std::endl;
};

bool                AForm::getSignature() const {
    return (signed_flag_);
};

const std::string   AForm::getTarget() const {
    return (target_);
}

unsigned int        AForm::getGradeToSign() const {
    return (grade_required_to_sign_form_);
};

unsigned int    AForm::getGradeToExecute() const {
    return (grade_required_to_execute_form_);
};

std::ostream &operator<<(std::ostream &outputstream, const AForm &form){
    outputstream << "Form name: " << form.getName() << std::endl
        << "Signed: " << (form.getSignature() ? "true" : "false") << std::endl
        << "Target: " << form.getTarget() << std::endl
        << "Grade required to sign form: " << form.getGradeToSign() << std::endl
        << "Grade required to execute form: " << form.getGradeToExecute() << std::endl;
    return (outputstream);
}

