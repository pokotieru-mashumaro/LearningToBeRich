#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << name << " is born!" << std::endl;
}

Zombie::~Zombie() {
    std::cout << _name << " is dead!" << std::endl;
}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
