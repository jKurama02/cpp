#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
# include<exception>

class NotFoundExeption : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Number not found");
		}
};



template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw (NotFoundExeption());
	else
		return (it);
}

