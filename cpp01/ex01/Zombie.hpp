#ifndef   Zombie_HPP
#define   Zombie_HPP

#include <iostream>

class Zombie {
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce() const;

private:
    std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
