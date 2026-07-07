#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span(unsigned int n) : _maxSize(n)
{
	_numbers.reserve(n);
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
		throw (Span::FullException());
	_numbers.push_back(n);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw (Span::NoSpanException());

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	unsigned int smallest = UINT_MAX;
	for (std::vector<int>::iterator it = sorted.begin(); it + 1 != sorted.end(); ++it)
	{
		unsigned int diff = *(it + 1) - *it;
		if (diff < smallest)
			smallest = diff;
	}
	return (smallest);
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw (Span::NoSpanException());

	std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());

	return (*maxIt - *minIt);
}

const char *Span::FullException::what() const throw()
{
	return ("Span is full");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Not enough numbers to find a span");
}