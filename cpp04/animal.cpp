#include "animal.hpp"


Animal::Animal(){};

Animal::Animal(std::string _type) : type(_type);

Animal::Animal operator=(Animal& other)
{
	if(this != &other)
	{

	}
}
