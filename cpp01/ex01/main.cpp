#include "Zombie.hpp"

int main()
{
	Zombie * horde = zombieHorde(5, "Fulvio");
	delete[] horde;
	return 0;
}
