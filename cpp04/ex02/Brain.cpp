#include "Brain.hpp"


Brain::Brain()
{
	std::cout << "base Brain creation\n";
};

Brain::Brain(const Brain &other)
{
	std::cout << "Constructor parametrized (Brain class) called\n";
	for(int i = 0; i < 100; i++)
	{                                                   ///////check se funziona
		this->ideas[i] = other.ideas[i];
	}
};

Brain &Brain::operator=(const Brain& other)
{
	if(this != &other)
	{                                                   ///////check se funziona
		for(int i = 0; i < 100; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	std::cout << "== Copy assigner (Brain class) called ==\n";
	return (*this);
};


Brain::~Brain() {
	std::cout << "    ~Called (Brain Class) Destructor~ \n";
};
