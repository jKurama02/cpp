#include "HumanB.hpp"
#include "Weapon.hpp"

void HumanB::attack()
{
	if(_weapon == 0)
		std::cout << _name << " has no weapon to attack with" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
