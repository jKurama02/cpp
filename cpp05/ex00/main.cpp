#include "Bureaucrat.hpp"

int main ()
{
	Bureaucrat Gino("Gino", 66);
	try
	{
		Bureaucrat pino("pino", -1);
	}
	catch(const std::exception &str)
	{
		std::cout << "Captured error :" << str.what();
	}

	try
	{
		Bureaucrat paolo("paolo", 160);

	}
	catch(const std::exception &str)
	{
		std::cout << "Captured error :" << str.what();
	}
	try
	{
		Bureaucrat perro("perro", 60);

	}
	catch(const std::exception &str)
	{
		std::cout << "Captured error :" << str.what();
	}
	Gino.decrement();
	Gino.increment();
	std::cout << Gino ;
	return 0;
}
