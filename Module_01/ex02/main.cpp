#include <string>
#include <iostream>

// ANSI escape codes for terminal colors
#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"

int main() { 

    std::string string      = "HI THIS IS BRAIN";
    std::string *stringPTR  = &string;
    std::string &stringREF  = string;

    std::cout << std::endl;
    std::cout << "Comparing String vs stringPTR vs stringREF:" << std::endl;
    std::cout << std::endl;
    std::cout << "Declaration and initialization done as:" << std::endl;
    std::cout << "\tstd::string " << BLUE << "string      = \"HI THIS IS BRAIN\";" << RESET << std::endl;
    std::cout << "\tstd::string *stringPTR  = &string;" << std::endl;
    std::cout << "\tstd::string &stringREF  = string;" << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Syntax to obtain address:\n";
    std::cout << "\tstd::cout "<< BLUE << "<< \"Address of string:\t\"<< &string " << RESET << "<< std::endl;" << std::endl;
    std::cout << "std::cout << \"Address of stringPTR:\t\"<< stringPTR << std::endl;" << std::endl;
    std::cout << "std::cout << \"Address of stringREF:\t\"<< &stringREF << std::endl;" << std::endl;
    std::cout << std::endl;
    std::cout << "Address of string:\t"<< &string << std::endl;
    std::cout << "Address of stringPTR:\t"<< stringPTR << std::endl;
    std::cout << "Address of stringREF:\t"<< &stringREF << std::endl;
     
    std::cout << std::endl;

    std::cout << "Syntax to get value:\n";
    std::cout << "\tstd::cout << \"Value of string:\t\t\t\"<< string << std::endl;\n \tstd::cout << \"Value pointed at by stringPTR:\t\" << *stringPTR << std::endl;\n \tstd::cout << \"Value referred by stringREF:\t\"<< stringREF << std::endl;\n" << std::endl;
    
    std::cout << "Value of string:\t\t"<< string << std::endl;
    std::cout << "Value pointed at by stringPTR:\t" << *stringPTR << std::endl;
    std::cout << "Value referred by stringREF:\t"<< stringREF << std::endl;

    std::cout << std::endl;
    return 0;
}
