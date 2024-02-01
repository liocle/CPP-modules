#ifndef INTERN_H
# define INTERN_H

# include <string>
# include "AForm.h"
# include "PresidentialPardonForm.h"
# include "ShrubberyCreationForm.h"
# include "RobotomyRequestForm.h"

class Intern {

private:
    AForm * makePresidentialPardonForm(const std::string target);
    AForm * makeShrubberyCreationForm(const std::string target);
    AForm * makeRobotomyRequestForm(const std::string target);
    
public:
    Intern();
    ~Intern();
    Intern(const Intern &other);
    Intern & operator=(const Intern &other);
    AForm * makeForm(std::string FormName, const std::string target);

};

#endif
