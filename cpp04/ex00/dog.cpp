#include "dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "base Dog creation\n";
};

Dog::Dog(std::string _type)
{
	std::cout << "String constructor (Dog class) called \n";

	this->type = _type;
}

Dog::Dog(const Dog& another) : Animal(another)
{
	std::cout << "Constructor parametrized (Dog class) called\n";
};

Dog &Dog::operator=(const Dog& other)
{
	if(this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "== Copy assigner (Dog class) called ==\n";
	return (*this);
}

void Dog::makeSound()
{
	std::cout << "****Dog sound****" << std::endl;
};

Dog::~Dog()
{
	std::cout << "****Dog sound****\n";
};

