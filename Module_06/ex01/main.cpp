#include "Serializer.hpp"
#include "Colors.h"
#include <iostream>

int main() {
    // Initialize Data instances with different values
    Data data = {42};
    std::cout << "Original data: " << CYAN << data.value << RESET << std::endl;
    std::cout << "Data's address: " << CYAN << &data << RESET << std::endl;


    // Serialize the Data pointers
    std::cout << "\nSerialization of data pointer..." << std::endl;
    std::cout << "The serialize function converts a Data pointer into a uintptr_t value using reinterpret_cast:" << std::endl;
    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Serialized uintptr_t: " << serialized << std::endl;
    std::cout << "Serialized's pointer address: " << &serialized << std::endl;
    

    // Deserialize back to Data pointers
    std::cout << "\nDeserialization of serialized pointer..." << std::endl;
    std::cout << "The deserialize function converts a uintptr_t value back into a Data pointer using reinterpret_cast:" << std::endl;
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer is: " << CYAN << deserialized << RESET << std::endl;
    std::cout << "Deserialized's value is: " << CYAN << deserialized->value << std::endl;
    return 0;
}

