#include "HumanA.hpp"
#include "Weapon.hpp"

int main ()
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	HumanA jym = HumanA("Jym", club);
	jym.attack();
	std::cout << club.getType() << std::endl;
	return 0;
}
