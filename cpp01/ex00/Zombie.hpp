#ifndef   Zombie_HPP
#define   Zombie_HPP

#include <iostream>

class Zombie {
public:
    Zombie(std::string name);
    ~Zombie();
    void announce() const;

private:
    std::string _name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);


#endif
