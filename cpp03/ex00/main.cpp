#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a;
    ClapTrap b("マイケル");

    std::cout << std::endl;

    a.attack("Bot1");
    a.takeDamage(10);
    a.takeDamage(20);
    a.display_me();
    a.beRepaired(5);
    a.beRepaired(4294967295);
    a.display_me();
    a.attack("Bot2");
    b.beRepaired(3);
    for (int i = 0; i < 10; i++)
        b.attack("サム");
    b.beRepaired(3);

    std::cout << std::endl;

    return (0);
}