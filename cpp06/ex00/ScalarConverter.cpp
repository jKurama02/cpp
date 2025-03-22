#include "ScalarConverter.hpp"

int ScalarConverter::count = 0;

ScalarConverter::ScalarConverter(int i)
{
	num = i;
	count++;
}

int ScalarConverter::getCount()
{
	return(this->count);
}
int ScalarConverter::getNum()
{
	return(this->num);
}

int ScalarConverter::addict(ScalarConverter* one, ScalarConverter* two)
{
	return(one->getNum() + two->getNum());
}
