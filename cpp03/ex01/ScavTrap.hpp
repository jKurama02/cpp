#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool _guardian_gate;
	public:
		ScavTrap(std::string name);
		~ScavTrap();
};
