#include "../includes/All.hpp"

int main(int ac, char **av)
{
	Server server;

	if (ac != 3)
	{
		std::cout << "Args: ./irc [port] [password]" << std::endl;
		return 1;
	}

	signal(SIGINT, Server::signal_handler);
	signal(SIGQUIT, Server::signal_handler);
	
	(void)av;
	std::cout << RED << "Let's Start!!" << std::endl;
}
