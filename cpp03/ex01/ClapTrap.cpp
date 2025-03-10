#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "~ClapTrap~ initialized \n";
};
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
};

void ClapTrap::attack(std::string const & target)
{
	if(this->_energyPoints >= 1 && this->_hitPoints >= 1)
	{
		std::cout << "ClapTrap " << this->_name <<" attacks " << target<<" , causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << "can't attacks \n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0) {
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " can't repair itself!" << std::endl;
	}
}



