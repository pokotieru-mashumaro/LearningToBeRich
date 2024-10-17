#ifndef   HumanB_HPP
#define   HumanB_HPP

#include <iostream>
# include "Weapon.hpp"

class HumanB {
private:
    std::string	_name;
    Weapon *_weapon;

public:
    HumanB(std::string name);
    ~HumanB();
	
    void	setWeapon(Weapon &weapon);
    void	attack(void) const;
};

#endif