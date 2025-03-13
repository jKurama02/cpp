#include "cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain;
	std::cout << "base Cat + Brain creation\n";
};

Cat::Cat(std::string _type)
{
	std::cout << "String constructor (Cat class + Brain) called \n";
	this->brain = new Brain;
	this->type = _type;
}

Cat::Cat(const Cat& another) : Animal(another)
{
	this->brain = new Brain(*(another.brain));
	std::cout << "Constructor parametrized (Cat class + Brain) called\n";
};

Cat &Cat::operator=(const Cat& other)
{
	if(this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*(other.brain));
	}
	std::cout << "== Copy assigner (Cat class) called ==\n";
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "****Cat sound****" << std::endl;
};

Cat::~Cat()
{
	delete brain;
	std::cout << "    ~Called (Cat Class) Destructor~\n";
};

