#ifndef BOXDRAWINGCLASS_H
# define BOXDRAWINGCLASS_H

# include <string>


/**
 * @brief A class representing box drawing characters for creating tables.
 *
 * This class provides static string constants for various box drawing characters,
 * facilitating the creation of tables and borders in the console.
 */
class BoxDrawing {

	public:

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
};

#endif // !BOXDRAWINGCLASS_H

