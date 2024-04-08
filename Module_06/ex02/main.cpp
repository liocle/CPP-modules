// main.cpp
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
    switch (rand() % 3) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return nullptr;  // Just to avoid compiler warning
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& base) {
    try {
        (void)dynamic_cast<A&>(base);
        std::cout << "A" << std::endl;
    } catch (std::bad_cast&) {
        try {
            (void)dynamic_cast<B&>(base);
            std::cout << "B" << std::endl;
        } catch (std::bad_cast&) {
            try {
                (void)dynamic_cast<C&>(base);
                std::cout << "C" << std::endl;
            } catch (std::bad_cast&) {}
        }
    }
    std::cout << std::endl;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << "Identifying classes with dynamic_cast and try/catch bad_cast:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        Base* base = generate();
        std::cout << "\tGenerated: ";
        identify(base);
        std::cout << "\tIdentified by reference: ";
        identify(*base);
        delete base;
    }

    return 0;
}
