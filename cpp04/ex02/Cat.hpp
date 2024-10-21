#ifndef   Cat_HPP
#define   Cat_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"


class Cat: public AAnimal
{
private:
	Brain *_brain;

public:
	Cat(void);
	Cat(const Cat &copy);
	~Cat();
	Cat& operator=(const Cat &copy);

    void makeSound(void)const;
	void getIdea(size_t i)const;
	void setIdea(size_t i, std::string idea);
};

#endif
