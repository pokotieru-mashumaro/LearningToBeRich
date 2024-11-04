#ifndef   Serializer_HPP
#define   Serializer_HPP

#include <iostream>
#include <stdint.h> // otherwise uintptr_t won't compile with c++98 standard

typedef struct Data
{
	std::string name;
} Data;


class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &copy);
	~Serializer();
	Serializer& operator=(const Serializer &copy);

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
