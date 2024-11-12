#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = copy;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
        {
            if (copy._ideas[i].length() > 0)
                this->_ideas[i] = copy._ideas[i];
        }
    }
    return *this;
}

const std::string Brain::getIdea(size_t i)const
{
	if (i < 100)
		return(this->_ideas[i]);
    return ("100以上は認められません");
}

const std::string *Brain::getIdeaAddress(size_t i)const
{
	if (i < 100)
	{
		const std::string	&address = this->_ideas[i];
		return(&address);
	}
	else
		return (NULL);
}

void Brain::setIdea(size_t i, std::string idea)
{
	if (i < 100)
		this->_ideas[i] = idea;
}

