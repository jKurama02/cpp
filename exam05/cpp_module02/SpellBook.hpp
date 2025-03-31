#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "Warlock.hpp"

class SpellBook
{
	private:
		std::map<std::string , ASpell*> spellBook;
		// SpellBook(const SpellBook& other);
		// SpellBook& operator=(const SpellBoook& other);
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell*);
};

#endif
