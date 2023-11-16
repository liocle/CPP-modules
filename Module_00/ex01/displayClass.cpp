// displayClass.cpp

#include "displayClass.hpp"
#include "boxDrawingClass.hpp"



void Display::welcomeMessage() {
	std::string welcomeString = "Welcome to the 80s and their unbelievable technology";
	std::cout << std::endl;
	std::cout << BoxDrawing::topLeftCorner;
	for (int i = 0; i < (int)welcomeString.size(); i++) {
		std::cout << BoxDrawing::horizontalBorder;
	}
	std::cout << BoxDrawing::topRightCorner << std::endl;

    std::cout << BoxDrawing::verticalBorder <<  welcomeString << BoxDrawing::verticalBorder << std::endl;

	std::cout << BoxDrawing::bottomLeftCorner;
	for (int i = 0; i < (int)welcomeString.size(); i++) {
		std::cout << BoxDrawing::horizontalBorder;
	}
	std::cout << BoxDrawing::bottomRightCorner << std::endl;
	waitForKeypress();
	clearScreen();
}

void Display::displayMenu() {
	std::string menu = "Modern phonebook action menu:";
	std::string actionDesired = "Enter the desired action in UPPERCASE";

	std::cout << BoxDrawing::menuTopLeftCorner;
	for (int i = 0; i < (int)menu.size(); i++) {
		std::cout << BoxDrawing::menuHorizontalBorder;
	}
	std::cout << BoxDrawing::menuTopRightCorner << std::endl;
	std::cout << BoxDrawing::menuVerticalBorder << menu << std::endl;
	std::cout << BoxDrawing::menuBottomLeftCorner << BoxDrawing::menuHorizontalBorder << BoxDrawing::menuTopDownSeparator;
	for (int i = 0; i < ((int)menu.size() - 2); i++) {
		std::cout << BoxDrawing::menuHorizontalBorder;
	}

	
    std::cout << "\tADD    - Add a contact" << std::endl;
    std::cout << "\tSEARCH - Dox a contact" << std::endl;
    std::cout << "\tEXIT   - Quit and lose your friends" << std::endl;
    std::cout << "" << std::endl;
}

std::string Display::getUserInput() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void Display::clearScreen() {
		std::cout << "\033[2J\033[1;1H";
}

void Display::waitForKeypress() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
