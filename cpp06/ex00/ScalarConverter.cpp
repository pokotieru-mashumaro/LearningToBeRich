#include "ScalarConverter.hpp"

std::string get_integer(const std::string& input);

void convert_char(const std::string& input);
void convert_int(const std::string& input);
void convert_float(const std::string& input);
void convert_double(const std::string& input);

bool is_impossible(const std::string& input);
bool is_pseudo(const std::string& input);
bool is_overflow(const std::string& input);

void output_result(const std::string& input);
void output_result_impossible();
void output_result_pseudo(const std::string& pseudo);

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    if (this != &copy)
    {}
    return *this;
}

void ScalarConverter::convert(const std::string& input)
{
	if (is_pseudo(input))
		return output_result_pseudo(input);
	if (is_impossible(input))
		return output_result_impossible();
	output_result(input);
}

void output_result(const std::string& input)
{
	convert_char(input);
	convert_int(input);
	convert_float(input);
	convert_double(input);
}

void output_result_impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void output_result_pseudo(const std::string& pseudo)
{
	std::string str;

	if (pseudo == "nan" || pseudo == "nanf")
		str = "nan";
	else if (pseudo == "-inf" || pseudo == "-inff")
		str = "-inf";
	else if (pseudo == "+inf" || pseudo == "+inff")
		str = "+inf";
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

void convert_char(const std::string& input)
{
	int input_integer = atoi(get_integer(input).c_str());
	char c = input_integer;

	if (input_integer < 32 || input_integer > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void convert_int(const std::string& input)
{
	if (is_overflow(input))
		std::cout << "int: impossible" << std::endl;
	else
	{
		int input_integer = atoi(get_integer(input).c_str());
		// int input_integer = ft_stoi(get_integer(input));
		std::cout << "int: " << input_integer << std::endl;
	}
}

void convert_float(const std::string& input)
{
	float cast = atof(input.c_str());
	std::cout << "float: " << cast << "f" << std::endl;
}

void convert_double(const std::string& input)
{
	float cast = atof(input.c_str());
	std::cout << "double: " << cast << std::endl;
}

bool is_impossible(const std::string& input)
{
	int f_count = 0;
	int dot_count = 0;
	int len = input.size();

	if (input == "")
		return true;
	if (input[0] != '-' && (input[0] < '0' || input[0] > '9'))
		return true;
	for (int i = 1; i < len; i++)
	{
		char c = input[i];
		if (c < '0' || c > '9')
		{
			if (c == 'f')
				f_count++;
			else if (c == '.')
			{
				if (f_count == 1)
					return true;
				else
					dot_count++;
			}
			else
				return true;
		}
	}
	if (f_count > 1 || dot_count > 1)
		return true;
	if (f_count == 1 && input.back() != 'f')
		return true;
	if (dot_count == 1 && input.back() == '.')
		return true;
	if (input.find(".f")!=std::string::npos || input.find("-f")!=std::string::npos || input.find("-.")!=std::string::npos)
		return true;
	return false;
}

bool is_pseudo(const std::string& input)
{
	if (input == "nan" || input == "nanf" || input == "-inf" ||  input == "+inf" ||  input == "-inff" ||  input == "+inff")
		return true;
	return false;
}

std::string get_integer(const std::string& input)
{
	std::string::size_type pos = input.find_first_of("f.");

	if (pos != std::string::npos)
		return input.substr(0, pos);
	else
		return input;
}

bool is_overflow(const std::string& input)
{
	std::string check_integer = get_integer(input);
	double stk = 0;
	bool is_minus = input[0] == '-' ? true : false;

	int len = check_integer.size();
	for (int i = is_minus ? 1 : 0; i < len; i++)
		stk = (stk * 10) + (check_integer[i] - '0');
	if (!is_minus && stk > 2147483647)
		return true;
	if (is_minus && stk > 2147483648)
		return true;
	return false;
}
