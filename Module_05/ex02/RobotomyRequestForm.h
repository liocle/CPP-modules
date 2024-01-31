
#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H 

# include "AForm.h"
# include <string>
# include <iostream>
# include "Colors.h"
# include "Bureaucrat.h"

class RobotomyRequestForm : public AForm{
public:
    RobotomyRequestForm(); 
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(const std::string target); 
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    virtual void execute(const Bureaucrat &executor) const override;

private:
    const std::string  target_;
    
};
#endif
