#include "Base.hpp"

Base* generate()
{
	std::srand(std::time(0));
	int i = std::rand() % 3;
	if(i == 0)
		return(new A);
	else if(i == 1)
		return(new B);
	else
		return(new C);
}
void identify(Base* p)
{
	std::cout << p->getTipe() << std::endl;
};
void identify(Base& p)
{
	std::cout << p.getTipe() << std::endl;
}

