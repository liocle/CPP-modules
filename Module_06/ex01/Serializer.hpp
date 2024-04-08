
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint>

class Serializer {
public:
    static uintptr_t serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }

    static Data* deserialize(uintptr_t raw) {
        return reinterpret_cast<Data*>(raw);
    }

private:
    Serializer() = delete; 
    Serializer(Serializer const &source) = delete;
    ~Serializer();

    Serializer &operator=(Serializer const &source) = delete;
};

#endif
