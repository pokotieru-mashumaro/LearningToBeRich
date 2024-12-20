#ifndef   ClapTrap_HPP
#define   ClapTrap_HPP

#include <iostream>

class ClapTrap {
private:
	std::string _name;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;

public:
	ClapTrap(void);
    ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap& operator=(const ClapTrap &copy);
	~ClapTrap();
	void attack(const std::string& target); 
	void takeDamage(unsigned int amount); 
	void beRepaired(unsigned int amount);
	void display_me();
};

#endif
