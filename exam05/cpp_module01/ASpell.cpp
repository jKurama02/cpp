#include "ASpell.hpp"

ASpell::ASpell(std::string n, std::string e) : name(n), effects(e){};

ASpell::ASpell(const ASpell& other)
{
	this->name = other.name;
	this->effects = other.effects;
}

ASpell& ASpell::operator=(const ASpell& other)
{
	if(this == &other)
		return *this;
	this->name = other.name;
	this->effects = other.effects;
	return *this;
}

ASpell::~ASpell(){};

std::string ASpell::getName() const{return this->name;}

std::string ASpell::getEffects() const{return this->effects;}


void ASpell::launch(const ATarget& other)
{
	other.getHitBySpell(*this);
}
