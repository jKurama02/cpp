#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <string>

#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;
	public:
		ASpell(std::string n, std::string e);
		ASpell(const ASpell& other);
		ASpell& operator=(const ASpell& other);
		virtual ~ASpell();
		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(const ATarget& other);
};

#endif
