#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <ostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(FragTrap& other);
		~FragTrap();
		void highFivesGuys(void);
		void attack(const std::string target);
	};

#endif

