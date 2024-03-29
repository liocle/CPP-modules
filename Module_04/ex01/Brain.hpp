
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

/**
 * @brief The Brain class managing an array of ideas.
 */
class Brain {
public:
    Brain();
    ~Brain();   // Ensures proper cleanup of dynamically allocated resources
    Brain( Brain const & src);
    Brain&  operator=( Brain const & rhs );
    /**
     * @brief Set an idea at a specific index.
     * @param index The index of the idea.
     * @param idea The idea to set.
     */
    void setIdea(unsigned int index, const std::string& idea);
    /**
     * @brief Get an idea at a specific index.
     * @param index The index of the idea.
     * @return The idea at the specified index.
     */
    std::string getIdea(int index) const;

private:
    std::string _ideas[100];
};

#endif
