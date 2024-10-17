#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	Zombie		*horde;
	int			n;
	std::string	name = "zombie";

	n = 6;
	horde = zombieHorde(n, name);

	for (int i = 0; i < n; i++)
		horde[i].announce();
	
	delete [] horde;
	return (0);
}