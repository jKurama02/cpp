#include "HumanA.hpp"
#include "Weapon.hpp"

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
