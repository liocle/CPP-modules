### Regular expression used to sanitize Numeric Input

This regex is used to validate numeric inputs, including integers, floating-point numbers, numbers in scientific notation, and special values like "nan", "inf", and "infinity". 
```
bool ScalarConverter::isValidNumericInput(const std::string& s) {
    // Regular expression to match a valid numeric input (including scientific notation and special floats)
    static const std::regex validNumericRegex(R"(^[+-]?(?:(?:\d+\.?\d*|\.\d+)(?:[eE][+-]?\d+)?|nanf?|inff?|infinity)$)",
                                              std::regex_constants::icase);
    return std::regex_match(s, validNumericRegex);
}
```

Explanation by component:

* ^: Matches the start of the string. Ensures that what follows is at the very beginning. 
* [+-]?:
    * []: Defines a character class, matching any one character inside the brackets.
    * +: Matches a literal plus sign.
    * -: Matches a literal minus sign.
    * ?: Makes the preceding element optional. So, [+-]? matches either a plus sign, a minus sign, or no sign at all.
* (?: ... ): A non-capturing group that groups multiple tokens together without capturing anything for back-referencing. It's used for grouping and/or applying quantifiers to part of the regex. 
* \d+\.?\d*:
    * \d: Matches any digit (equivalent to [0-9]).
    * +: Ensures that the preceding element (\d in this case) appears one or more times.
    * \.?: Matches a literal dot (.) zero or one time, making the decimal point optional.
    * \d*: Ensures that the digit may appear zero or more times after the decimal point.
* |\.\d+: An alternative within the non-capturing group.
    * |: Logical OR operator that allows for alternative matches (this or that).
    * \.: Matches a literal dot, representing the decimal point.
    * \d+: One or more digits must follow the decimal point.
* (?:[eE][+-]?\d+)?:
    * [eE]: Matches either an e or E, used in scientific notation to denote the exponent.
    * [+-]?: Optionally matches either a plus or minus sign, indicating the sign of the exponent.
    * \d+: One or more digits, specifying the magnitude of the exponent.
    * ?: The whole exponent part is optional.
* nanf?|inff?|infinity:
    * nan: Matches the string "nan".
    * f?: Optionally matches the letter "f", making "nanf" also a valid match.
    * |: OR operator for alternative matches.
    * inf: Matches the string "inf".
    * f?: Optionally matches "f", so "inff" is also valid.
    * |: Another OR operator.
    * infinity: Matches the literal string "infinity".
* $: Matches the end of the string, ensuring that the pattern must match the entire string. 
