#include "Warlock.hpp"
#include "ASpell.hpp"

Warlock::Warlock(){};

Warlock::Warlock(const Warlock& other)
{
	this->name = other.name;
	this->title = other.title;
	std::cout << this->name << ": This looks like another boring day.\n";
}
Warlock& Warlock::operator=(const Warlock& other)
{
	if(this == &other)
		return *this;
	this->name = other.name;
	this->title = other.title;
	return *this;
}

Warlock::~Warlock(){
	std::cout<< this->name<<": My job here is done!"<<std::endl;
};

const std::string& Warlock::getName() const
{
	return(this->name);
}

const std::string& Warlock::getTitle() const
{
	return(this->title);
}
void Warlock::setTitle(const std::string& string)
{
	this->title = string;
}

void Warlock::setName(const std::string& string)
{
	this->name = string;
}

Warlock::Warlock(std::string n, std::string t) : name(n), title(t){
	std::cout << this->name << ": This looks like another boring day.\n";
}


void Warlock::introduce() const
{
	std::cout << getName()<< ": I am "<< getName()<<", "<<getTitle()<<"!"<<std::endl;
}


void Warlock::learnSpell(ASpell* other)
{
	this->spellofbook.learnSpell(other);
}

void Warlock::forgetSpell(std::string nameSpell)
{
	this->spellofbook.forgetSpell(nameSpell);
}

void Warlock::launchSpell(std::string spellName , ATarget& other)
{
	ASpell * pur = spellofbook.createSpell(spellName);
	if(pur)
	{
		pur->launch(other);
	}
}
