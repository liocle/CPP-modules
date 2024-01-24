

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>

class Bureaucrat {

private:
    const std::string   name_;
    int                 grade_; 
    Bureaucrat();

public:
    Bureaucrat(const std::string name_, int grade_) throw ();
    Bureaucrat(Bureaucrat &other);
    ~Bureaucrat();

    Bureaucrat & operator=(Bureaucrat & other);
    Bureaucrat & operator<<(Bureaucrat & other);
    
    std::string     getName();
    int             getGrade();
    void            incrementGrade();
    void            decrementGrade();

    class GradeTooHighException : public std::exception {
        public:
            GradeTooHighException() ;
            ~GradeTooHighException() = default;

        virtual const char *what() const noexcept {
            return ("Grade is too High");
        }
    };

    class GradeTooLowException : public std::exception {
        public:
            GradeTooLowException()   noexcept = default;
            ~GradeTooLowException() = default;

        virtual const char *what() const noexcept {
            return ("Grade is too Low");
        }
    };
};

#endif
