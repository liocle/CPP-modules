#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "AForm.h"
# include <string>
# include <iostream>
# include "Colors.h"
# include "Bureaucrat.h"

class PresidentialPardonForm : public AForm{
public:
    PresidentialPardonForm(); 
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(const std::string target); 
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    virtual void execute(const Bureaucrat &executor) const override;

private:
    const std::string  target_;
    
};
#endif
