#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP
#include <string>
#include <map>
#include "ASpell.hpp"
class ASpell;

class SpellBook
{
	private:
		std::map<std::string , ASpell*> book;
		// SpellBook(const SpellBook& other);
		// SpellBook& operator=(const SpellBoook& other);
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell*);
		void forgetSpell(std::string const &other);
		ASpell* createSpell(std::string const &spell);
};

#endif
