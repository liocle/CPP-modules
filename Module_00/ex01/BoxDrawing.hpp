#ifndef BOXDRAWINGCLASS_H
# define BOXDRAWINGCLASS_H

# include <string>
# include <iostream>


/**
 * @brief A class representing box drawing characters for creating tables.
 *
 * This class provides static string constants for various box drawing characters,
 * facilitating the creation of tables and borders in the console.
 */
class BoxDrawing {

	public:

    BoxDrawing() { std::cout << "BoxDrawing constructor called "  << std::endl; }

		// Menu box drawing characters 
		static const std::string menuTopLeftCorner;
		static const std::string menuTopRightCorner;
		static const std::string menuBottomLeftCorner;
		static const std::string menuBottomRightCorner;

		static const std::string menuHorizontalBorder;
		static const std::string menuVerticalBorder;

		static const std::string menuVerticalLeftSeparator;
		static const std::string menuVerticalRightSeparator;

		static const std::string menuTopDownSeparator;
		static const std::string menuBottomUpSeparator;

		// Contact table drawing characters
		static const std::string topLeftCorner;
		static const std::string topRightCorner;
		static const std::string bottomLeftCorner;
		static const std::string bottomRightCorner;

		static const std::string horizontalBorder;
		static const std::string verticalBorder;

		static const std::string verticalLeftSeparator;
		static const std::string verticalRightSeparator;

		static const std::string innerSeparator;

		static const std::string topDownSeparator;
		static const std::string bottomUpSeparator;

		static const std::string vanishingHorizontalLine;
		static const std::string vanishingVerticalLine;

		
};

#endif // !BOXDRAWINGCLASS_H

