#include "Zombie.hpp"

Zombie::Zombie()
{
    this->_name = "John Smith";
}

Zombie::Zombie(std::string name)
{
    this->_name = name;
}

Zombie::~Zombie() {
}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
