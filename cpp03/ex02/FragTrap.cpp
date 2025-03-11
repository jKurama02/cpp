#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){};

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "~FragTrap~ initialized \n";
	this->_attackDamage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
};

void FragTrap::attack(const std::string target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "FragTrap " << this->_name << " attacks " << target
					<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << "can't attacks \n";
	}
};

FragTrap::~FragTrap()
{
	std::cout << "FragTrap has been destroyed!" << std::endl;
};

FragTrap::FragTrap(FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called \n";
};

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " requests a positive high five from everyone!" << std::endl;

};
