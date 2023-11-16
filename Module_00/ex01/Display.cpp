// displayClass.cpp

#include "Display.hpp"
#include "BoxDrawing.hpp"



void Display::welcomeMessage() {
	std::string welcomeString = " Welcome to the 80's and their unbelievable technology ";
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
	std::string menu = " 👾 Modern phonebook action menu powered by Vim <3 👾 ";
	std::string actionDesired = "Enter the desired action in UPPERCASE";

	// Print menu string top box
	std::cout << BoxDrawing::menuTopLeftCorner;
	for (int i = 0; i < (int)menu.size() - 4; i++) {
		std::cout << BoxDrawing::menuHorizontalBorder;
	}
	std::cout << BoxDrawing::menuTopRightCorner << std::endl;
	// Print menu string within the box
	std::cout << BoxDrawing::menuVerticalBorder << menu << BoxDrawing::menuVerticalBorder << std::endl;
	// Print menu string bottom box
	std::cout << BoxDrawing::menuBottomLeftCorner;
	for (int i = 0; i < 7 ; i++) {
		std::cout << BoxDrawing::menuHorizontalBorder;
	}
	std::cout << BoxDrawing::menuTopDownSeparator;
	for (int i = 0; i < ((int)menu.size() - 12); i++) {
		std::cout << BoxDrawing::menuHorizontalBorder;
	}
	std::cout << BoxDrawing::menuBottomRightCorner << std::endl;
	
	// Print action choice
    std::cout << "\t" << BoxDrawing::menuVerticalBorder << " ADD    - Add a contact" << std::endl;
    std::cout << "\t" << BoxDrawing::menuVerticalBorder << " SEARCH - Dox a contact" << std::endl;
    std::cout << "\t" << BoxDrawing::menuVerticalBorder << " EXIT   - Quit and lose your friends" << std::endl;
	std::cout << BoxDrawing::topLeftCorner;
	for (int i = 0; i < 7 ; i++) {
		std::cout << BoxDrawing::horizontalBorder;
	}
	std::cout << BoxDrawing::bottomUpSeparator;
	for (int i = 0; i < ((int)menu.size() - 12); i++) {
		std::cout << BoxDrawing::horizontalBorder;
	}
	for (int i = 0; i < 8; i++) {
		std::cout << BoxDrawing::vanishingHorizontalLine;
	}
    std::cout << std::endl << BoxDrawing::verticalBorder << "Choosen action in UPPERCASE please: ";
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
