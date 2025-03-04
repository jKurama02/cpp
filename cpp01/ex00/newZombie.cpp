#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie* newZombie = new Zombie;
	newZombie->set_name(name);
	newZombie->announce();
	return newZombie;
};
