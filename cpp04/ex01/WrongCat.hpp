#ifndef   WrongCat_HPP
#define   WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat &copy);
	~WrongCat();
	WrongCat& operator=(const WrongCat &copy);

    void makeSound(void)const;
};

#endif
