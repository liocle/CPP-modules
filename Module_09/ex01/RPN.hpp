#ifndef RPN_HPP
#define RPN_HPP

#include <stdexcept>
#include <string>

/**
 * @brief RPN class to evaluate reverse polish arithmetic. No object is instantiated.
 * 
 * This class is designed to evaluate expressions in Reverse Polish Notation (RPN).
 * It does not allow instantiation, copying, or assignment of objects.
 */
class RPN {

   public:
    // Deleted constructors and destructors to prevent object instantiation
    RPN() = delete;
    ~RPN() = delete;
    RPN(const RPN& other) = delete;
    RPN const& operator=(const RPN& other) = delete;

    /**
     * @brief Evaluates a given RPN expression.
     * 
     * @param input The RPN expression as a string.
     * @return The result of the evaluation as an integer.
     * @throws RPNException if the expression is invalid or an error occurs during evaluation.
     */
    static int evaluate(const std::string& input);

    // Exception class for RPN errors
    class RPNException : public std::runtime_error {
       public:
        RPNException(const std::string& message) : std::runtime_error(message) {}
    };
};

#endif  // RPN_HPP
