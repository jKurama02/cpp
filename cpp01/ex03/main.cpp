#include "HumanA.hpp"
#include "Weapon.hpp"

int main ()
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	return 0;
}
