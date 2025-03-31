#ifndef FWOOSH_HPP
#define FWOOSH_HPP

// al posto dei Inclusion Guards si potrebbe usare  (#pragma once)

#include "Warlock.hpp"
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();
		ASpell* clone() const;
};

#endif
