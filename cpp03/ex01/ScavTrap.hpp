#ifndef   ScavTrap_HPP
#define   ScavTrap_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
    ScavTrap();
    ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	ScavTrap& operator=(const ScavTrap &copy);
	~ScavTrap();
    
	void attack(const std::string& target); 
    void guardGate();
};

#endif
