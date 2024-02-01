#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>

# define  MIN_GRADE_TO_SIGN     21
# define  MIN_GRADE_TO_EXECUTE  42

class Bureaucrat;

class AForm {
private:
    const std::string     name_;
    bool                  signed_flag_;
    const unsigned int    grade_required_to_sign_form_;
    const unsigned int    grade_required_to_execute_form_;
    const std::string     target_;

public:
    AForm();
    virtual ~AForm();
    AForm(const AForm &other);
    AForm(const std::string name_, const unsigned int grade_to_sign, const unsigned int grade_to_execute, const std::string target_);
    AForm & operator=(const AForm &other);

    void                  beSigned(Bureaucrat & a_bureaucrat);
    bool                  getSignature() const;
    const std::string     getName() const;
    const std::string     getTarget() const;
    unsigned int    getGradeToSign() const;
    unsigned int    getGradeToExecute() const;
    virtual void    execute(const Bureaucrat &executor) const = 0;

    
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const noexcept {
            return ("Form::GradeTooHighException caught");
        }
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const noexcept {
            return ("Form::GradeTooLowException caught");
        }
    };

};

std::ostream &operator<<(std::ostream &outputstream, const AForm &form_name);
#endif
