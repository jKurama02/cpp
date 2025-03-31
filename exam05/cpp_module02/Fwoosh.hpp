#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include "Warlock.hpp"
#include "ASpell.hpp"
#include <string>

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();
		ASpell* clone() const;
};

#endif
