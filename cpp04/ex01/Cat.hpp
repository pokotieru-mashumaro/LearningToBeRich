#ifndef   Cat_HPP
#define   Cat_HPP

#include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat(void);
	Cat(const Cat &copy);
	~Cat();
	Cat& operator=(const Cat &copy);

    void makeSound(void)const;
};

#endif
