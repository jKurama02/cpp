#include "easyfind.hpp"
#include <deque>
#include <list>

int main()
{
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	try
	{
		std::cout << *easyfind(v, 6) << std::endl;
		std::cout << *easyfind(v, 50) << std::endl;
		std::cout << *easyfind(v, 40) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
