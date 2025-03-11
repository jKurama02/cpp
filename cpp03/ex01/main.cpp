#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main ()
{
	ScavTrap a("palo");
	a.attack("gino");
	ScavTrap b(a);
	return 0;
}
