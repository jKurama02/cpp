#ifndef ATARGET_HPP
#define ATARGET_HPP
#include "ASpell.hpp"
#include <string>
class ASpell;


class ATarget
{
	private:
		std::string type;
	public:
		ATarget(std::string t);
		ATarget(const ATarget& other);
		ATarget& operator=(const ATarget& other);
		virtual ~ATarget();

		virtual ATarget* clone() const = 0;
		std::string getType() const;

		void getHitBySpell(const ASpell& other) const;

};

#endif
