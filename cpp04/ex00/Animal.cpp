#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal Default constructor called" << std::endl;
	_type = "Animal";
}

Animal::Animal(const Animal &copy) {
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = copy;
}

// Destructor
Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}


Animal &Animal::operator=(const Animal &copy) {
	std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return *this;
}

void Animal::makeSound(void)const
{
    std::cout << "Animalには声がない。" << std::endl;
}

std::string	Animal::getType(void)const
{
	return (this->_type);
}