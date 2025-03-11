#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	this->_gate = 0;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "~ScavTrap~ initialized \n";
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	this->_gate = 0;
};

void ScavTrap::attack(const std::string enemy)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "ScavTrap " << this->_name << " attacks " << enemy
					<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << "can't attacks \n";
	}
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap in Gate keeper MODE\n";
	this->_gate = 1;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap has been destroyed!" << std::endl;
};



ScavTrap::ScavTrap(ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called \n";
};
