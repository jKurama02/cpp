#include <cmath>
#include <iostream>
#include <limits>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Wrong argument\n";
		return (0);
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

