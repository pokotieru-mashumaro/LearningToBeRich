#include <iostream>

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Args: ./irc [port] [password]" << std::endl;
		return 1;
	}

}
