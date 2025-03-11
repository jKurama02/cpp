#include "ScavTrap.hpp"
#include <iostream>


ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << name << " costruito!\n";
}
