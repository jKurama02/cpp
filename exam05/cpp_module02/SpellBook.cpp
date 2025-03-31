#include "SpellBook.hpp"
#include "ASpell.hpp"

SpellBook::SpellBook() {};

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it = book.begin();
	while (it != book.end())
	{
		delete it->second;
		it++;
	}
	book.clear();
}

void SpellBook::learnSpell(ASpell *other)
{
	if (book.find(other->getName()) == book.end())
	{
		book[other->getName()] = other->clone();
	}
}
void SpellBook::forgetSpell(std::string const &other)
{
	std::map<std::string, ASpell *>::iterator it = book.begin();
	if (book.find(other) != book.end())
	{
		delete it->second;
		book.erase(it);
	}
}

ASpell* SpellBook::createSpell(std::string const &spell)
{
	ASpell *tmp = NULL;
	if(book.find(spell) != book.end())
	{
		tmp = book[spell];
	}
	return tmp;
}
