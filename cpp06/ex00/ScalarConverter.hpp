#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <math.h>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <limits>
#include <iomanip>

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter& operator=(const ScalarConverter &other);
	~ScalarConverter();
	public:

	bool static is_char(const std::string &str);
	bool static is_int(const std::string &str);
	bool static is_float(const std::string &str);
	bool static is_double(const std::string &str);
	void static convert(const std::string &str);
};

#endif

