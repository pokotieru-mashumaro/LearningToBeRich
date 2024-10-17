#include <iostream>

int main() 
{
	std::string	s = "HI THIS IS BRAIN";
	std::string	*stringPTR = &s;
	std::string &stringREF = s;

	std::cout << "the string variable's address: " << &s << std::endl;
	std::cout << "stringPTR's address: " << stringPTR << std::endl;
	std::cout << "stringREF's address: " << &stringREF << std::endl;
	std::cout << "the string variable's value: " << s << std::endl;
	std::cout << "stringPTR's value: " << *stringPTR << std::endl;
	std::cout << "stringREF's value: " << stringREF << std::endl;

	return (0);
}