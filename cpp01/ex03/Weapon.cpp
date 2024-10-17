#include "Weapon.hpp"

Weapon::Weapon()
{
    this->_type = "John Smith";
}

Weapon::Weapon(std::string type)
{
    this->_type = type;
}

Weapon::~Weapon()
{
	return ;
}

std::string const &Weapon::getType(void) const {
    return (this->_type);
}

void Weapon::setType(std::string type) {
    _type = type;
}