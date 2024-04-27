#include <iostream>
#include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <expression>\n";
        return 1;
    }
    RPN calculation;

    try {
        int result = calculation.evaluate(argv[1]);
        if (result != -1) {
            std::cout << result << std::endl;
        }
    } catch (std::exception const& e) {
        std::cerr << "Exception caughter " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
