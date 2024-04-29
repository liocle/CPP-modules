#ifndef RPN_HPP
# define RPN_HPP

#include <stdexcept>
#include <string>

class RPN {
private:
  RPN(const RPN &other) = delete;
  RPN const &operator=(const RPN &other) = delete;

public:
  RPN() = delete;
  ~RPN() = delete;
  static int evaluate(const std::string &input);

  class RPNException : public std::runtime_error {
  public:
    RPNException(const std::string &message) : std::runtime_error(message) {}
  };
};

#endif // RPN_HPP
