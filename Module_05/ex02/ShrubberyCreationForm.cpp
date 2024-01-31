#include "ShrubberyCreationForm.h"
#include "Colors.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("A default shrubbery form", 145, 137, "default location"), target_("Default location"){
    std::cout << LIGHT_GREEN << "Default ShrubberyCreationForm constructor was called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm () {
    std::cout << LIGHT_GREEN << "Shrubbery destructed oke" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("A Shrubbery form", 145, 137, target), target_(target) {
    std::cout << LIGHT_GREEN << "ShrubberyCreationForm constructor was called for target: " << target << RESET << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other) : AForm(other), target_(other.target_)  {
    std::cout << LIGHT_GREEN << "Copy constructor for ShrubberyCreationForm was called" << RESET << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (this->getSignature() == true) {
        if (executor.getGrade() <= this->getGradeToExecute()) {
            std::ofstream file(target_ + "_shrubbery", std::ios::app);
            if (!file) {
                std::cerr << "File could not be created" << std::endl;
                return;
            }
            file << ".  . .  .  . .  .  . .  .  . .  .  . .  .  . . . .. .. .. . .  . .  .  . .  .  . .  .  . .  .  .  " << std::endl;
            file << "   .       .       .       .       .  . .. .. .  8X8@X8@X8@t8: . .     .       .       .       .   ." << std::endl;
            file << "     .  .    .  .    .  .    .  . . .X8%@t8@@%X:8t%X:.  t8@8%%88.  ..    .  .    .  .    .  .    .  " << std::endl;
            file << " .       .       .       .     .  @8X@888@XSS@@8@t. .  ..:  SX8888;8:. .     .       .       .      " << std::endl;
            file << "   .  .    .  .    .  .   ... . t88X...;..  .. @@;    .@t   .::  8@@8@S@. .    .  .    .  .    .  . " << std::endl;
            file << "  .    .  .    .  .    ..  8888@8X   . ..     ::.. .  X  ;       .:  8.@@..  .   .  .   .   .   .   " << std::endl;
            file << "    .       .       . . %@SXX %%XX.@ S .. .  ... .    8  t       .   . t@8:.   .      .   .   .    ." << std::endl;
            file << "  .   . .    .  .    ..X;.t;:.   S   t:@X . .t%.   .  8;.%           ..88X . .    .         .    .  " << std::endl;
            file << "    .     .    .  . . S%@ . .     X    8:;. ;;.;t.. X;8.        .  ..S8;8% .    .   .  . .     .    " << std::endl;
            file << "  .    .   .       . ttS .    .   ;..    @  :t ..;t8X8. XS8Xt88.    :SX88..   .    .       .  .   . " << std::endl;
            file << "     .   .   .  .  . 88     .           . t.  8t:8@::.. S      8     . 888%. .   .   . .        .   " << std::endl;
            file << "  .    .      .   .   X     .            8@              S%%  .8         ;8..  .         . . .     ." << std::endl;
            file << "    .     . .   .  . t8; X88 :8.8:       8%    8%:;t;;tt%t   :8.         88  .    . .  .       . .  " << std::endl;
            file << "  .   .           . X;         88.X%;t : @X  .%tS8. .. ...:::8t%88   .. 8X%:.   .        .  .       " << std::endl;
            file << "    .   . .  . .  . @%X   8;S     .;8;8S@X:. S:S 8.@S     .  ...tt  .:888S:.  .     . .       .  .  " << std::endl;
            file << "  .         .    .  :8t:           X8 X%:. . S    88t8t    .. .  ..88tX8;.      .       . . .     . " << std::endl;
            file << "     . .  .    .   . t8888SX@%XXSS%8...@8... 8X     8@88X8 ..;8X88@t XXt  . .     .  .        . .   " << std::endl;
            file << "  .          .       .  %8X888%...:   ..SX .  S        S%@SSSX8%X   ..  .     . .      .  .        ." << std::endl;
            file << "    .  . . .    . .     .:. ... ..  . . %X :  t            .    .  .      .  .     . .      .  .    " << std::endl;
            file << "  .           .                         t .   % .         . ..   .    . .       .      . .   .   .  " << std::endl;
            file << "    . .  .  .   .  . .    .  .  . . . .   ;   %               .     .      .  .   .  .     .      . " << std::endl;
            file << "  .       .   .        .   .            . :   t.  .  .  . .     . .    .  .     .       .     . .   " << std::endl;
            file << "     . .         .  .    .    . .  .  . :    S@ .           . .     .       . .    .  .   . .      ." << std::endl;
            file << "  .      . . .  . .   .     .    . .  . @  . 8:.. ....... .  .  .     . .        .      .      .    " << std::endl;
            file << "    .  .           . ...  .    .    .   ;:   t8 :        :X@@St   .  .    . .  .    .      .    . . " << std::endl;
            file << "  .      .  . . .. t:X@:.. .....t Xt. .S@:;;:SS@.;t;;tttt.::::. ;; .    .         .   .  .   .      " << std::endl;
            file << "    . .            .t8%.:;tttttt X.  : . . .. .  . ... ..  . . .      .    . .  .      .   .   .  ." << std::endl;
            std::cout << RESET << target_ << "_shrubbery was delivered in the current directory" << std::endl;
            file.close();
        }
        else 
            throw GradeTooLowException();
    }
    else 
        std::cerr << RESET << "You want a shrubbery in target: " << target_ << "? Get your Shrubbery form signed first" << std::endl;
}
