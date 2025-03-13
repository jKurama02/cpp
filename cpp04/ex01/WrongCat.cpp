#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "base WrongCat creation\n";
};

WrongCat::WrongCat(std::string _type)
{
	std::cout << "String constructor (WrongCat class) called \n";

	this->type = _type;
}

WrongCat::WrongCat(const WrongCat& another) : WrongAnimal(another)
{
	std::cout << "Constructor parametrized (WrongCat class) called\n";
};

WrongCat &WrongCat::operator=(const WrongCat& other)
{
	if(this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cout << "== Copy assigner (WrongCat class) called ==\n";
	return (*this);
}

void WrongCat::makeSound()
{
	std::cout << "****WrongCat sound****" << std::endl;
};

WrongCat::~WrongCat()
{
	std::cout << "****WrongCat sound****\n";
};

