#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <expression>\n";
    return 1;
  }
    try {
      int result = RPN::evaluate(argv[1]);
      std::cout << "Result: " << result << std::endl;
    } catch (std::exception const &e) {
      std::cerr << "Error: " << e.what() << std::endl;
      return 1;
    }
    return 0;
}
