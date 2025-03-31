#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include "Warlock.hpp"
#include "ASpell.hpp"
#include <string>

class Polymorph : public ASpell
{
	public:
		Polymorph();
		~Polymorph();
		ASpell* clone() const;
};

#endif
