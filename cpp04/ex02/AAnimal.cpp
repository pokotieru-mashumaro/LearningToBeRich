#include "AAnimal.hpp"

AAnimal::AAnimal() {
    std::cout << "AAnimal Default constructor called" << std::endl;
	_type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &copy) {
	std::cout << "AAnimal Copy constructor called" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy) {
	std::cout << "AAnimal Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return *this;
}

void AAnimal::makeSound(void)const
{
    std::cout << "AAnimalには声がない。" << std::endl;
}

std::string	AAnimal::getType(void)const
{
	return (this->_type);
}