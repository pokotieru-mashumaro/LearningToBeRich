#ifndef   Dog_HPP
#define   Dog_HPP

#include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog(void);
	Dog(const Dog &copy);
	~Dog();
	Dog& operator=(const Dog &copy);

    void makeSound(void)const;
};

#endif
