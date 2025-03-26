#include "Data.hpp"

Data::Data(){};

Data::Data(int value) : i(value){};

Data::Data(const Data& other)
{
	*this = other;
}
Data& Data::operator=(const Data& other)
{
	if(this == &other)
		return *this;
	this->i = other.i;
	return *this;
}
