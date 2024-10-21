#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat Default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat &copy) {
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = copy;
}

// Destructor
Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return *this;
}

void Cat::makeSound(void)const
{
	std::cout << this->getType() << " << にゃー" << std::endl;
}
