#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include "Warlock.hpp"
#include "ASpell.hpp"

class Fireball : public ASpell
{
	public:
		Fireball();
		~Fireball();
		ASpell* clone() const;
};

#endif
