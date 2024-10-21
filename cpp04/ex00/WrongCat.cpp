#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat Default constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) {
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return *this;
}

void WrongCat::makeSound(void)const
{
	std::cout << this->getType() << " << にゃー2" << std::endl;
}
