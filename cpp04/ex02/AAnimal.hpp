#ifndef   AAnimal_HPP
#define   AAnimal_HPP

#include <iostream>

class AAnimal 
{
protected:
	std::string _type;

public:
	AAnimal(void);
	AAnimal(const AAnimal &copy);
	virtual ~AAnimal();
	AAnimal&	operator=(const AAnimal &copy);

	virtual void makeSound(void)const = 0;
	std::string	getType(void)const;
};


#endif
