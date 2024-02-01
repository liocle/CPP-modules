#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "AForm.h"
# include "Bureaucrat.h"
# include <string>
# include <iostream>
# include <fstream>

class ShrubberyCreationForm : public AForm{
public:
    ShrubberyCreationForm(); 
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string target); 
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    virtual void execute(const Bureaucrat &executor) const override;

private:
    const std::string  target_;
    
};
#endif

