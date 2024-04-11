#include "whatever.hpp"
#include <iostream>

struct Student {
  std::string name;
  int grade;

  bool operator<(const Student &rhs) const { return (this->grade < rhs.grade); }
  bool operator>(const Student &rhs) const { 
    return (this->grade > rhs.grade); }
};

std::ostream &operator<<(std::ostream &os, const Student &student) {
  os << student.name << " is graded: " << student.grade;
  return os;
};

int main(void) {
  /**
   * The double colons :: in C++ are known as the scope resolution operator.
   * When used before a function or variable name like ::swap(a, b);, it
   * explicitly instructs the compiler to use the global version of the function
   * or variable.
   */
  {
    // SWAP TEMPLATE //
    std::cout << "_____SWAP TEMPLATE____" << std::endl;
    int int_1{1};
    int int_2{2};

    std::cout << "Initial values:\nint_1: " << int_1 << "\nint_2: " << int_2
              << std::endl;
    ::swap(int_1, int_2);
    std::cout << "Swapped values:\nint_1: " << int_1 << "\nint_2: " << int_2
              << std::endl;

    std::cout << "\nUsing the swap template with a different type:\n"
              << std::endl;

    std::string str_1{"string_1"};
    std::string str_2{"string_2"};

    std::cout << "Initial values:\nstr_1: " << str_1 << "\nstr_2: " << str_2
              << std::endl;
    ::swap(str_1, str_2);
    std::cout << "Swapped values:\nstr_1: " << str_1 << "\nstr_2: " << str_2
              << std::endl;
  }
  {
    // MIN TEMPLATE //
    std::cout << "\n_____MIN TEMPLATE____" << std::endl;
    int int_1{21};
    int int_2{42};

    std::cout << "\nInitial values:\nint_1: " << int_1 << "\nint_2: " << int_2
              << std::endl;

    std::cout << "Min value is:\n: " << ::min(int_1, int_2) << std::endl;

    std::cout << "\nUsing the min template with a different type:\n"
              << std::endl;

    std::string str_1{"toto"};
    std::string str_2{"tata"};

    std::cout << "Initial values:\nstr_1: " << str_1 << "\nstr_2: " << str_2
              << std::endl;
    std::cout << "Min value is: " << ::min(str_1, str_2) << std::endl << std::endl;

    Student toto{"t0t0_1", 0};
    Student tata{"t0t0_2", 20};
    std::cout << "Student 1 data: " << toto << std::endl;
    std::cout << "Student 2 data: " << tata << std::endl;
    std::cout << "Min student grade is: " << ::min(toto, tata).grade
              << std::endl;
  }

  {
    // MAX TEMPLATE //
    std::cout << "\n_____MAX TEMPLATE____" << std::endl;
    int int_1{21};
    int int_2{42};

    std::cout << "Initial values:\nint_1: " << int_1 << "\nint_2: " << int_2
              << std::endl;

    std::cout << "max value is: " << ::max(int_1, int_2) << std::endl << std::endl;

    std::cout << "\nUsing the max template with a different type:\n"
              << std::endl;

    std::string str_1{"toto"};
    std::string str_2{"tata"};
    std::cout << "Initial values:\nstr_1: " << str_1 << "\nstr_2: " << str_2
              << std::endl;

    std::cout << "max value is: " << ::max(str_1, str_2) << std::endl << std::endl;;

    Student toto{"t0t0_1", 0};
    Student tata{"t0t0_2", 20};
    std::cout << "Student 1 data: " << toto << std::endl;
    std::cout << "Student 2 data: " << tata << std::endl;
    std::cout << "Max student grade is: " << ::max(toto, tata).grade
              << std::endl;
  }
  {
    std::cout << "\n_____SUBJECT MAIN_____" << std::endl;
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    return 0;
  }
}
