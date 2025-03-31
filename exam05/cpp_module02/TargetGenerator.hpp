#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP
#include "Warlock.hpp"
#include <string>

class ATarget;
class TargetGenerator
{
	private:
		std::map<std::string , ATarget*> targets;
		// TargetGenerator(const SpellBook& other);
		// SpellBook& operator=(const SpellBoook& other);
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &other);
		ATarget* createTarget(std::string const &spell);
};

#endif
