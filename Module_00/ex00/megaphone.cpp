#include <cctype>
#include <iostream>
#include <iostream>

int main(int argc, char **argv) {

  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else {

    for (int i = 1; i < argc; i++) {

      std::string argument(argv[i]);
      for (int j = 0; argument[j] != '\0'; j++) {

        char &c = argument[j];
        c = std::toupper(c);
      }
      std::cout << argument;
    }
  }
  std::cout << std::endl;
  return (0);
}
