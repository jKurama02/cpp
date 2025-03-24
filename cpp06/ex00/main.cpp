#include <cmath>
#include <iostream>
#include <limits>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
		return 0;
		(void)argc;


	//_________myTests

	// (void)argv;
	// const std::string a = "66";
	// const std::string b = "nan";
	// const std::string c = "78.9";
	// const std::string d = "4.0f";
	// ScalarConverter::convert(a);
	// ScalarConverter::convert(b);
	// ScalarConverter::convert(c);
	// ScalarConverter::convert(d);

	//_____subjectForm_____
	ScalarConverter::convert(argv[1]);

	return 0;
}

