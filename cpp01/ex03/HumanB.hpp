#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

#include <string>
#include <iostream>

class HumanB
{
	private:
			std::string _name;
			Weapon* _weapon;
		public:
			HumanB(std::string name): _name(name), _weapon(0){};
			void setWeapon(Weapon &weapon)
			{
				this->_weapon = &weapon;
			};
			void attack();
			~HumanB(){};
};

#endif
