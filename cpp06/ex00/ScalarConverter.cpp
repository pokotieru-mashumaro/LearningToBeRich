#include "ScalarConverter.hpp"

bool is_char(const std::string &input);
bool is_int(const std::string &input);
bool is_float(const std::string &input);
bool is_double(const std::string &input);
bool is_pseudo(const std::string &input);

bool is_number(const std::string &input);
int dot_count(const std::string &input);
std::string get_integer(const std::string& input);

int type_check(const std::string &input);

void convert_char(const std::string& input);

void output_char(const std::string &input);
void output_int(const std::string &input);
void output_float(const std::string &input);
void output_double(const std::string &input);
void output_psedo(const std::string& input);
void output_impossible();

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
	{
	}
	return *this;
}

void ScalarConverter::convert(const std::string &input)
{
	int type = type_check(input);

	switch (type)
	{
	case TYPE_CHAR:
		output_char(input);
		break;
	case TYPE_INT:
		output_int(input);
		break;
	case TYPE_FLOAT:
		output_float(input);
		break;
	case TYPE_DOUBLE:
		output_double(input);
		break;
	case TYPE_PSEUDO:
		output_psedo(input);
		break;
	default:
		output_impossible();
		break;
	}
}

int type_check(const std::string &input)
{
	if (is_char(input))
		return TYPE_CHAR;
	else if (is_int(input))
		return TYPE_INT;
	else if (is_float(input))
		return TYPE_FLOAT;
	else if (is_double(input))
		return TYPE_DOUBLE;
	else if (is_pseudo(input))
		return TYPE_PSEUDO;
	return TYPE_IMPOSSIBLE;
}

void output_char(const std::string &input)
{
	int num = static_cast<int>(input[0]);

	std::cout << "char: " << input[0] << std::endl;
	std::cout << "int: " << num << std::endl;
    std::cout << "float: " << num << ".0f" << std::endl;
    std::cout << "double: " << num << ".0" << std::endl;
}

void output_int(const std::string &input)
{
    long long check_num = atoll(input.c_str());
    if (check_num > INT_MAX || check_num < INT_MIN)
    {
        output_impossible();
        return;
    }
    int num = static_cast<int>(check_num);

    convert_char(input);
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << num << ".0f" << std::endl;
    std::cout << "double: " << num << ".0" << std::endl;
}

void output_float(const std::string &input)
{
    double num = atof(input.c_str());
    long num2 = atol(input.c_str());

    convert_char(input);
    
    if (num2 > INT_MAX || num2 < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << num2 << std::endl;

	if (num > FLT_MAX || num < -FLT_MAX)
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		std::cout << "float: " << num << "f" << std::endl;
    	std::cout << "double: " << num << std::endl;
	}
}

void output_double(const std::string &input)
{
	double num = atof(input.c_str());
	long num2 = atol(input.c_str());

	convert_char(input);
	
	if (num2 > INT_MAX || num2 < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << num2 << std::endl;
	
	if (num > FLT_MAX || num < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << num << "f" << std::endl;
	std::cout << "double: " << num << std::endl;
}

void output_psedo(const std::string& input)
{
	std::string str;

	if (input == "nan" || input == "nanf")
		str = "nan";
	else if (input == "-inf" || input == "-inff")
		str = "-inf";
	else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
		str = "+inf";
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

void output_impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void convert_char(const std::string& input)
{
	int input_integer = atoi(get_integer(input).c_str());
	char c = input_integer;

	if (input_integer < 0 || input_integer > 255)
		std::cout << "char: impossible" << std::endl;
	else if (input_integer < 32 || input_integer > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

bool is_char(const std::string &input)
{
	if (input.size() == 1 && (input[0] < '0' || input[0] > '9'))
		return true;
	return false;
}

bool is_number(const std::string &input)
{
	bool is_minus = input[0] == '-';
	if ((is_minus && input[1] == '.') || (!is_minus && input[0] == '.') || input[input.size() - 1] == '.' || (input[input.size() - 1] == 'f' && input[input.size() - 2] == '.'))
		return false;
	for (size_t i = is_minus ? 1 : 0; i < input.size() - 1; i++)
	{
		if ((input[i] < '0' || input[i] > '9') && input[i] != '.')
			return false;
	}
	return true;
}

int dot_count(const std::string &input)
{
	int count = 0;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == '.')
			count++;
	}
	return count;
}

bool is_int(const std::string &input)
{
	if (input[0] != '-' && (input[0] < '0' || input[0] > '9'))
		return false;
	for (size_t i = 1; i < input.size(); i++)
	{
		if (input[i] < '0' || input[i] > '9')
			return false;
	}
	return true;
}

bool is_float(const std::string &input)
{
	bool end_is_f = input[input.size() - 1] == 'f';
	int dots = dot_count(input);
	bool is_num = is_number(input);

	if (dots <= 1 && is_num && end_is_f)
		return true;
	return false;
}

bool is_double(const std::string &input)
{
	int dots = dot_count(input);
	bool is_num = is_number(input);

	if (dots <= 1 && is_num)
		return true;
	return false;
}

bool is_pseudo(const std::string &input)
{
	if (input == "nan" || input == "nanf" || input == "-inf" || input == "+inf" || input == "inf" || input == "-inff" || input == "+inff" || input == "inff")
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