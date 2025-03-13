#include "dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain;
	std::cout << "base Dog + Brain creation\n";
};

Dog::Dog(std::string _type)
{
	std::cout << "String constructor (Dog class + Brain) called \n";
	this->brain = new Brain;
	this->type = _type;
}

Dog::Dog(const Dog& another) : Animal(another)
{
	this->brain = new Brain(*(another.brain));
	std::cout << "Constructor parametrized (Dog class + Brain) called\n";
};

Dog &Dog::operator=(const Dog& other)
{
	if(this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*(other.brain));
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
	delete brain;
	std::cout << "    ~Called (Dog Class) Destructor~\n";
};
