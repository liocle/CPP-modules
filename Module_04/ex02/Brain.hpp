
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
public:
    Brain();
    ~Brain();
    Brain( Brain const & src);
    Brain&  operator=( Brain const & rhs );

    void setIdea(unsigned int index, const std::string& idea);
    std::string getIdea(int index) const;

private:
    std::string _ideas[100];
};

#endif
