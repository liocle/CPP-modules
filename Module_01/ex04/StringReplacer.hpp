#ifndef STRINGREPLACER_HPP
# define STRINGREPLACER_HPP

# include <string>

class StringReplacer {

public:
    StringReplacer(const char *filename, const char *s1, const char *s2);

    void replace_and_write_to_file(void);


private:
    std::string     _filename;
    std::string     _s1;
    std::string     _s2;

    void      check_strings_validity(std::string _s1, std::string _s2);
    void      check_file_validity(void);
};
#endif
