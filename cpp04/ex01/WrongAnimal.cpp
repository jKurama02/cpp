#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "base WrongAnimal creation\n";
};

WrongAnimal::WrongAnimal(std::string _type) : type(_type)
{
	std::cout << "String constructor (WrongAnimal class) called \n";
};

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "Constructor parametrized (WrongAnimal class) called\n";
	this->type = other.type;
};

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
	if(this != &other)
	{
		this->type = other.type;
		return (*this);
	}
	else
		return(*this);
	std::cout << "== Copy assigner (WrongAnimal class) called ==\n";
};

void WrongAnimal::makeSound()
{
	std::cout << "****WrongAnimal sound****\n";
};

std::string WrongAnimal::getType()
{
	return(this->type);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "    ~Called (WrongAnimal Class) Destructor~ \n";
};
