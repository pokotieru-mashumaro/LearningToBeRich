#include "ScavTrap.hpp"

int main(void)
{
    {
        std::cout << "ClapTrap" << std::endl;

        ClapTrap a;
        ClapTrap b("マイケル");

        std::cout << std::endl;

        a.attack("Bot1");
        a.takeDamage(10);
        a.takeDamage(20);
        a.beRepaired(5);
        a.attack("Bot2");
        b.beRepaired(3);
        for (int i = 0; i < 10; i++)
            b.attack("サム");
        b.beRepaired(3);

        std::cout << std::endl;
    }
    {
        
        std::cout << "\n\nScavTrap" << std::endl;
        ScavTrap c;
        ScavTrap d("アルキメデス");

        std::cout << std::endl;

        c.attack("Bot1");
        c.beRepaired(22);
        c.takeDamage(21);
        c.beRepaired(22);
        c.guardGate();
        c.guardGate();
        d.attack("Bot2");
        d.takeDamage(101);
        d.takeDamage(15);
        d.attack("Bot3");

        std::cout << std::endl;

    }
    return (0);
}