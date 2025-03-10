#include "ClapTrap.hpp"

int main ()
{
	ClapTrap c("pino");
	c.attack("timmy");
	c.takeDamage(4);
	c.beRepaired(2);
	return 0;
}
