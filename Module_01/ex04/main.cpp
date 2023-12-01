#include <iostream>
#include "StringReplacer.hpp"

/**
 * @brief Main function to replace strings in a file.
 *
 * @param argc Number of command-line arguments.
 * @param argv Command-line arguments.
 * @return 0 on success, 1 on error.
 */
int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    const char  *filename = argv[1];
    const char  *s1 = argv[2];
    const char  *s2 = argv[3];
    
    try {
        // Create a StringReplacer instance and perform the replacement
        StringReplacer  StringReplacerInstance(filename, s1, s2);
        StringReplacerInstance.replace_and_write_to_file();
        
        // Print success message
        std::cout << "Replacement successful. Check " << filename << ".replace file." << std::endl;
        return (0);
    } catch (const std::exception &e) {
        // Print error message on exception
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}
