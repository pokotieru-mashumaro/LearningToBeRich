#ifndef   Dog_HPP
#define   Dog_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
private:
	Brain *_brain;

public:
	Dog(void);
	Dog(const Dog &copy);
	~Dog();
	Dog& operator=(const Dog &copy);

    void makeSound(void)const;
	void getIdea(size_t i)const;
	void setIdea(size_t i, std::string idea);

};

#endif
