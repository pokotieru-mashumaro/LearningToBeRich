#ifndef   ScalarConverter_HPP
#define   ScalarConverter_HPP

#include <iostream>
#include <sstream>
#include <float.h>
#include <stdlib.h>
#include <climits>
#include <cmath>
#include <iomanip>

#define TYPE_CHAR 0
#define TYPE_INT 1
#define TYPE_FLOAT 2
#define TYPE_DOUBLE 3
#define TYPE_PSEUDO 4
#define TYPE_IMPOSSIBLE 5

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
