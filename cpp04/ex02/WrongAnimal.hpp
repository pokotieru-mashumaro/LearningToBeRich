#ifndef   WrongAnimal_HPP
#define   WrongAnimal_HPP

#include <iostream>

class WrongAnimal 
{
protected:
	std::string _type;

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &copy);
	virtual ~WrongAnimal();
	WrongAnimal&	operator=(const WrongAnimal &copy);

	void makeSound(void)const;
	std::string	getType(void)const;
};


#endif
