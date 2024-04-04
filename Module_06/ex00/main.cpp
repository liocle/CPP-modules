#include <iostream>
#include "ScalarConverter.h"

int main(int argc, char** argv) {

    if (argc != 2) {
        std::cout << "Use: ./convert argument_to_be_converted" << std::endl;
        return (0);
    }
    std::string input = argv[1];
    if (input.length() == 0) {
        std::cout << "Empty input" << std::endl;
        return 0;
    }
    try {
        ScalarConverter::convert(input);
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;

}
    return 0;
}
