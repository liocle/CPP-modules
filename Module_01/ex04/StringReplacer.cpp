#include "StringReplacer.hpp"
#include <stdexcept>
#include <fstream>


StringReplacer::StringReplacer (const char *filename, const char *s1, const char *s2) 
    : _filename(filename), _s1(s1), _s2(s2) {};

void    StringReplacer::check_strings_validity(std::string _s1, std::string _s2){
    if (_s1.empty() || _s2.empty()) {
        throw std::invalid_argument("s1 and s2 must not be empty");
    }
}


void StringReplacer::check_file_validity(void) {
    std::ifstream file(_filename);

    if (!file.is_open()) {
        throw std::runtime_error("Error opening file: " + _filename);
    }
}

void    StringReplacer::replace_and_write_to_file (void) {
        check_strings_validity( _s1, _s2);
        check_file_validity();



    
}

