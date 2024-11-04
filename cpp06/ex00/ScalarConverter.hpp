#ifndef   ScalarConverter_HPP
#define   ScalarConverter_HPP

#include <iostream>
#include <sstream>

class ScalarConverter
{
private:
    ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter &copy);

public:
	static void convert(const std::string& input);
};

#endif
