 

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>

# define    MAX_GRADE 1
# define    MIN_GRADE 150

class Bureaucrat {

private:
    const std::string   name_;
    int                 grade_; 

public:
    Bureaucrat();
    Bureaucrat(const std::string name_, int grade_);
    Bureaucrat(Bureaucrat &other);
    ~Bureaucrat();

    Bureaucrat & operator=(const Bureaucrat &other);
    
    std::string     getName() const;
    int             getGrade() const;
    void            incrementGrade();
    void            decrementGrade();
    void            signForm(Form &form);

    class GradeTooHighException : public std::exception {
        public:
        virtual const char *what() const noexcept {
            return ("Bureaucrat::GradeTooHighException caught");
        }
    };

    class GradeTooLowException : public std::exception {
        public:
        virtual const char *what() const noexcept {
            return ("Bureaucrat::GradeTooLowException caught");
        }
    };
};

std::ostream & operator<<(std::ostream &outputstream, const Bureaucrat &a_bureaucrat);

#endif
