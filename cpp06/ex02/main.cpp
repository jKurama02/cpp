#include "Base.hpp"
// #include "A.hpp"
// #include "B.hpp"
// #include "C.hpp"


int main()
{
	Base *ptr =	generate();

	
	identify(*ptr);
	identify(ptr);
	std::cout << ptr << std::endl;
	std::cout << &ptr << std::endl;
}
