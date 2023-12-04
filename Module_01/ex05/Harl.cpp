
#include "Harl.hpp"

Harl::Harl() {};

Harl::~Harl() {};

void Harl::debug(void) {
    std::cout << "🐛 DEBUG 🐛 I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "ℹ️  INFO ℹ️  I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "⚠️  WARNING⚠️: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "👻 ERROR 👻 This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    const int numLevels = 4;
    const char* levels[numLevels] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*functions[numLevels])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < numLevels; i++) {
        if (level == levels[i]) {
            (this->*functions[i])();
            return;
        }
    }

    std::cout << "💩Invalid complaint level💩: " << level << std::endl;
}
