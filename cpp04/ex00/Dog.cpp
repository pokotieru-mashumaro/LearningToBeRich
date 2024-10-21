#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog Default constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &copy) {
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = copy;
}

// Destructor
Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
	std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return *this;
}

void Dog::makeSound(void)const
{
	std::cout << this->getType() << " << わんわん" << std::endl;
}
