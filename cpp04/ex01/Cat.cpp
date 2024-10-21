#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default constructor called" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = copy;
}

Cat::~Cat()
{
    delete (this->_brain);
    std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
        this->_brain = new Brain();
        if (this->_brain == NULL)
            exit(1);
        *this->_brain = *copy._brain;
        return *this;
    }
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << this->getType() << " << にゃー" << std::endl;
}

void	Cat::getIdea(size_t i)const
{
	std::cout << "idea[" << i << "]: " << this->_brain->getIdea(i) << " : address: " << this->_brain->getIdeaAddress(i) << std::endl;
}

void	Cat::setIdea(size_t i, std::string idea)
{
		this->_brain->setIdea(i, idea);
}

