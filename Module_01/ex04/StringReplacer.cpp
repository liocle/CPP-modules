#include "StringReplacer.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>


/**
 * @brief Constructs a StringReplacer object with the specified parameters.
 *
 * @param filename The name of the file to be processed.
 * @param s1 The string to be replaced in the file.
 * @param s2 The string to replace occurrences of s1 in the file.
 */
StringReplacer::StringReplacer (const char *filename, const char *s1, const char *s2) 
: _filename(filename), _s1(s1), _s2(s2) {};


/**
 * @brief Checks the validity of the replacement strings.
 *
 * @throw std::invalid_argument if either s1 or s2 is empty.
 */
void    StringReplacer::check_strings_validity(){
    if (_s1.empty() || _s2.empty()) {
        throw std::invalid_argument("s1 and s2 must not be empty");
    }
}

/**
 * @brief Reads the content of the file and stores it in _file_content.
 *
 * This function assumes the file has been checked for validity.
 * Iterator Concept:
 * 
 * An iterator is an object that allows you to iterate (loop) through a sequence of elements.
 * In this case, std::istreambuf_iterator<char> is an iterator designed to read characters from an input stream (file_stream in this case).
 * Default Constructor of std::istreambuf_iterator:
 * 
 * The line std::istreambuf_iterator<char> endIterator; declares an iterator named endIterator.
 * The default constructor of std::istreambuf_iterator creates an iterator that represents the end of the stream. It essentially points to no specific element.
 * String Constructor Using Iterators:
 * 
 * The std::string constructor used here takes two iterators (startIterator and endIterator) as arguments.
 * It constructs a string using the characters between these iterators. In this context, it reads characters from file_stream and stores them in _file_content.
 */
void    StringReplacer::check_file_validity_and_get_content(void){
    std::ifstream file_stream(_filename);
    if (!file_stream.is_open()) {
        throw std::runtime_error("Error opening file: " + _filename);
    }
    std::istreambuf_iterator<char> startIterator(file_stream);
    std::istreambuf_iterator<char> endIterator;
    _file_content = std::string(startIterator, endIterator);
}

/**
 * @brief Replaces occurrences of s1 with s2 in _file_content.
 */
void   StringReplacer::replace_s1_occurrence(void) {
    size_t position = _file_content.find(_s1);
    while (position != std::string::npos){
        _file_content.erase(position, _s1.length());
        _file_content.insert(position, _s2);
        position = _file_content.find(_s1, position + _s2.length());
    }
}

/**
 * @brief Writes the content of _file_content to a new file.
 *
 * @throw std::Error creating or writing to .replace file.
 */
void    StringReplacer::write_to_file(void) {
    std::ofstream  new_file(_filename + ".replace");
    if (new_file.is_open()){
        new_file << _file_content;
        new_file.close();
    }
    else {
        std::cerr << "Error creating or writing to file: " + _filename + ".replace" << std::endl;
    }

}


/**
 * @brief Replaces occurrences of s1 with s2 in the file and writes to a new file.
 */
void    StringReplacer::replace_and_write_to_file (void) {
    check_strings_validity();
    check_file_validity_and_get_content();
    replace_s1_occurrence();
    write_to_file();
}

