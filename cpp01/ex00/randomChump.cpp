#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie zombie1;
	zombie1.set_name(name);
	zombie1.announce();
}
