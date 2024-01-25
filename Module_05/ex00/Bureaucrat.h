

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
    Bureaucrat();

public:
    Bureaucrat(const std::string name_, int grade_);
    Bureaucrat(Bureaucrat &other);
    ~Bureaucrat();

    Bureaucrat & operator=(Bureaucrat &other);
    std::ostream & operator<<(std::ostream &outputstream, Bureaucrat &a_bureaucrat);
    
    std::string     getName();
    int             getGrade();
    void            incrementGrade();
    void            decrementGrade();

    class GradeTooHighException : public std::exception {
        public:
            GradeTooHighException()   noexcept = default;
            ~GradeTooHighException() = default;

        virtual const char *what() const noexcept {
            return ("Bureaucrat::GradeTooHighException caught");
        }
    };

    class GradeTooLowException : public std::exception {
        public:
            GradeTooLowException()   noexcept = default;
            ~GradeTooLowException() = default;

        virtual const char *what() const noexcept {
            return ("Bureaucrat::GradeTooLowException caught");
        }
    };
};

#endif
