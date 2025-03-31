#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include <string>
#include <map>
#include "SpellBook.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"


class ASpell;
class ATarget;
class SpellBook;




class Warlock
{
	private:
		Warlock(const Warlock& other);
		Warlock& operator=(const Warlock& other);
		std::string name;
		std::string title;
		SpellBook spellofbook;

	public:
		Warlock();
		Warlock(std::string n, std::string t);
		~Warlock();

		const std::string& getName() const;
		const std::string& getTitle() const;

		void introduce() const;

		void setTitle(const std::string& string);
		void setName(const std::string& string);

		void learnSpell(ASpell* other);
		void forgetSpell(std::string nameSpell);
		void launchSpell(std::string spellName , ATarget& other);
};


#endif
//=const= alla fiene delle dichiarazioni dei metodi
