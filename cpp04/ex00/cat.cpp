#include "cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "base Cat creation\n";
};

Cat::Cat(std::string _type)
{
	std::cout << "String constructor (Cat class) called \n";

	this->type = _type;
}

Cat::Cat(const Cat& another) : Animal(another)
{
	std::cout << "Constructor parametrized (Cat class) called\n";
};

Cat &Cat::operator=(const Cat& other)
{
	if(this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "== Copy assigner (Cat class) called ==\n";
	return (*this);
}

void Cat::makeSound()
{
	std::cout << "****Cat sound****" << std::endl;
};

Cat::~Cat()
{
	std::cout << "****Cat sound****\n";
};

