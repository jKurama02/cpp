#include "Zombie.hpp"

int main()
{
	Zombie * my_zombie = newZombie("Fulvio");
	randomChump("Peter");
	delete my_zombie;
	return 0;
}
