#include "Zombie.hpp"

int	main(void)
{
	std::cout << "スタック" << std::endl;
	Zombie	zombie1("Zombie1");
	Zombie	zombie2("Zombie2");

	zombie1.announce();
	zombie2.announce();
	randomChump("randomChumpZ");

	std::cout << std::endl;

	std::cout << "ヒープメモリ" << std::endl;
	Zombie	*zombie3;

	zombie3 = newZombie("Zombie3");
	zombie3->announce();
	delete zombie3;

	return (0);
}