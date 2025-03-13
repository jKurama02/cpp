#include "animal.hpp"


Animal::Animal()
{
	std::cout << "base Animal creation\n";
};

Animal::Animal(std::string _type) : type(_type)
{
	std::cout << "String constructor (Animal class) called \n";
};

Animal::Animal(const Animal &other)
{
	std::cout << "Constructor parametrized (Animal class) called\n";
	this->type = other.type;
};

Animal &Animal::operator=(const Animal& other)
{
	if(this != &other)
	{
		this->type = other.type;
		return (*this);
	}
	else
		return(*this);
	std::cout << "== Copy assigner (Animal class) called ==\n";
};

void Animal::makeSound() const
{
	std::cout << "****Animal sound****\n";
};

std::string Animal::getType()
{
	return(this->type);
}

Animal::~Animal() {
	std::cout << "    ~Called (Animal Class) Destructor~ \n";
};
