#include "Weapon.hpp"


Weapon::Weapon(std::string Type): _type(Type) {};

const std::string& Weapon::getType() const
{
	return (this->_type);
}

void Weapon::setType(std::string newType)
{
	this->_type = newType;
	// (_type = newType;) stessa cosa , la differenza e' che (this->) specifica il MEMBRO DELLA CLASSE
}
Weapon::~Weapon()
{
};
