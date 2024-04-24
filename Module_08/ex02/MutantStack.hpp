/**
 * @file MutantStack.hpp
 * @brief Extends std::stack to provide iterator support.
 *
 * The MutantStack class is a template class that extends the std::stack
 * container adapter by enabling iteration over its elements. It inherits
 * from std::stack while using std::deque as the underlying container.
 *
 * @tparam T Type of the elements.
 */
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

/**
 * @class MutantStack
 * @brief Extends std::stack by adding iterator capabilities.
 *
 * This class provides a stack with the added ability to be iterated over,
 * something not possible with the standard std::stack. It exposes iterators
 * of the underlying deque container, allowing both forward and reverse iteration.
 *
 * @tparam T Specifies the type of the elements stored in the stack.
 */
template <typename T>
class MutantStack : public std::stack<T, std::deque<T>> {
   private:
    MutantStack(const MutantStack& source) = delete; // Copy constructor deleted to prevent unintended duplication of the container's content
    MutantStack operator=(const MutantStack& source) = delete; // Assignement operator deleted to avoid copying

   public:
    MutantStack() {};
    ~MutantStack() {};    
    /**
     * @brief Inherit constructors from the base std::stack class.
     *
     * Utilizes the constructor of the std::stack<T, std::deque<T>>,
     * allowing initialization using the same parameters as the underlying deque.
     */
    using std::stack<T, std::deque<T>>::stack;  

    // Iterator typdefs
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;
    typedef typename std::deque<T>::reverse_iterator reverse_iterator;
    typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

    // Returns const/-iterators to the beginning/end of the reversed/-stack
    iterator begin() { return this->c.begin(); }    // Returns an iterator to the beginning of the stack
    iterator end() { return this->c.end(); }        // Returns an iterator to the end of the stack 

    const_iterator begin() const { return this->c.begin(); } 
    const_iterator end() const { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};
#endif  // MUTANTSTACK_HPP
