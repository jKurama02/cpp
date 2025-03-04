#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if(N < 0)
		return NULL;
	Zombie* horde = new Zombie[5];

	for(int i = 0; i < N; i++)
	{
		horde[i].set_name(name);
		horde[i].announce();
	}
	return horde;
};
