#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog Default constructor called" << std::endl;
	this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog &copy) {
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog() {
    delete(this->_brain);
	std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
	std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
        this->_brain = new Brain();
        if (this->_brain == NULL)
            exit(1);
        *this->_brain = *copy._brain;

    }
    return *this;
}

void Dog::makeSound(void)const
{
	std::cout << this->getType() << " << わんわん" << std::endl;
}

void	Dog::getIdea(size_t i)const
{
	std::cout << "idea[" << i << "]: " << this->_brain->getIdea(i) << " : address: " << this->_brain->getIdeaAddress(i) << std::endl;
}

void	Dog::setIdea(size_t i, std::string idea)
{
		this->_brain->setIdea(i, idea);
}

