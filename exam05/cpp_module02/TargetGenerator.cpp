#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::TargetGenerator() {};

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it = targets.begin();
	while (it != targets.end())
	{
		delete it->second;
		it++;
	}
	targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *other)
{
	if (targets.find(other->getType()) == targets.end())
	{
		targets[other->getType()] = other->clone();
	}
}
void TargetGenerator::forgetTargetType(std::string const &other)
{
	std::map<std::string, ATarget *>::iterator it = targets.begin();
	if (targets.find(other) != targets.end())
	{
		delete it->second;
		targets.erase(it);
	}
}

ATarget* TargetGenerator::createTarget(std::string const &spell)
{
	ATarget *tmp = NULL;
	if(targets.find(spell) != targets.end())
	{
		tmp = targets[spell];
	}
	return tmp;
}
