#include "SpellBook.hpp"
#include "ASpell.hpp"

SpellBook::SpellBook(){};

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell*>::iterator it = spellBook.begin();
	while(it != spellBook.end())
	{
		delete it->second;
		it++;
	}
	spellBook.clear();
}

void SpellBook::learnSpell(ASpell* other)
{
	if(SpellBook.find(other->getName()) == SpellBook.end())
	{
		SpellBook[other->getName()] = other->clone();
	}
}
