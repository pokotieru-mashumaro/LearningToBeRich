#include "DiamondTrap.hpp"

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

    {
        std::cout << "\n\nFragTrap" << std::endl;
        FragTrap e;
        FragTrap f("ザーサイ");

        std::cout << std::endl;
        e.highFivesGuys();
        e.attack("Bot1");
        e.takeDamage(101);
        e.takeDamage(1);
        e.attack("Bot2");
        f.highFivesGuys();
        std::cout << std::endl;
    }
    {
        std::cout << "\n\nDiamondTrap" << std::endl;
        DiamondTrap a;
        DiamondTrap b("魔王");
        DiamondTrap c(a);

        std::cout << std::endl;
        a.whoAmI();
        a.attack("Bot1");
        b.whoAmI();
        b.attack("Bot2");
        c.whoAmI();
        std::cout << std::endl;
    }
    return (0);
}