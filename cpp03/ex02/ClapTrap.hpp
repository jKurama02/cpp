#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		std::string _name;
		int 		_hitPoints;
		int			_energyPoints;
		int 		_attackDamage;

		public:
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(ClapTrap &other);
			~ClapTrap();
			void attack(std::string const & target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
};

#endif
