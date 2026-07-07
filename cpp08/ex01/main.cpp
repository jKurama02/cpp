#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(42);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::vector<int> numbers;
	for (int i = 0; i < 10000; i++)
		numbers.push_back(std::rand());

	Span big(10000);
	big.addRange(numbers.begin(), numbers.end());
	std::cout << "shortest (big): " << big.shortestSpan() << std::endl;
	std::cout << "longest (big): " << big.longestSpan() << std::endl;

	Span empty(3);
	try
	{
		std::cout << empty.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}