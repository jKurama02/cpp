#include "ATarget.hpp"
#include <iostream>

ATarget::ATarget(std::string t) : type(t){};

ATarget::ATarget(const ATarget& other)
{
	this->type = other.type;
}

ATarget& ATarget::operator=(const ATarget& other)
{
	if(this == &other)
		return *this;
	this->type = other.type;

	return *this;
}

ATarget::~ATarget(){};

std::string ATarget::getType() const{return this->type;}

void ATarget::getHitBySpell(const ASpell& other) const
{
	std::cout << this->getType() <<  " has been " << other.getEffects() << "!" << std::endl;
}
