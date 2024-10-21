#ifndef   Brain_HPP
#define   Brain_HPP

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
