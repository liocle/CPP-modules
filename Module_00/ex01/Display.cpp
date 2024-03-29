// displayClass.cpp

#include "Display.hpp"



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


/**
 * @brief Displays the main menu with available actions.
 *        Prompts the user to enter their desired action.
 */
void Display::displayMenu() {
	std::string menu = "     Modern phonebook action menu     ";
	std::string actionDesired = "Enter the desired action in UPPERCASE";

	// Print menu string top box
	std::cout << BoxDrawing::menuTopLeftCorner;
	for (int i = 0; i < (int)menu.size(); i++) {
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
	for (int i = 0; i < ((int)menu.size() - 8); i++) {
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
	for (int i = 0; i < 10; i++) {
		std::cout << BoxDrawing::vanishingHorizontalLine;
	}
    std::cout << std::endl << BoxDrawing::verticalBorder << "Chosen action in UPPERCASE please: ";
}

/**
 * @brief Reads a line of user input from the standard input.
 * @return A string containing the user input.
 */
std::string Display::getUserInput() {
    std::string input;
	PhoneBook::myGetLine(input);
    return input;
}

/**
 * @brief Clears the terminal screen.
 */
void Display::clearScreen() {
		std::cout << "\033[2J\033[1;1H";
}

/**
 * @brief Waits for the user to press Enter before continuing.
 */
void Display::waitForKeypress() {
    std::cout << std::endl << "\t-  Press Enter to continue  - ";
    if (std::cin.eof())
        exit(0);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
}
