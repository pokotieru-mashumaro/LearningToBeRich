#ifndef   Animal_HPP
#define   Animal_HPP

#include <iostream>

class Animal 
{
protected:
	std::string _type;

public:
	Animal(void);
	Animal(const Animal &copy);
	virtual ~Animal();
	Animal&	operator=(const Animal &copy);

	virtual void makeSound(void)const;
	std::string	getType(void)const;
};


#endif
