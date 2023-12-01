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
    std::string     _file_content;

    void        check_strings_validity(void);
    void        check_file_validity_and_get_content(void);
    void        check_file_validity(void);
    void        read_file_content(void);
    void        replace_s1_occurrence(void);
    void        write_to_file(void);
};
#endif
