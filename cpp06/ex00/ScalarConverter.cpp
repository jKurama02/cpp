#include "ScalarConverter.hpp"
#include <string>

ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
};

ScalarConverter::~ScalarConverter(){};

bool ScalarConverter::is_char(const std::string &str)
{
	if(str.empty())
		return false;
	if(str.length() != 1)
	{
		return false;
	}
	return true;
}

bool ScalarConverter::is_int(const std::string &str)
{
	unsigned long i = 0;
	if(str.empty())
		return false;
	while(str[i] == '-' || str[i] == '+')
		i++;
	if(i == str.length())
		return false;
	while(i < str.length())
	{
		if(!std::isdigit(str[i]))
			return false;
		i++;
	}
	long num = std::strtol(str.c_str(),NULL, 10);
	if(num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		return false;
	return true;
}

void ScalarConverter::convert(const std::string &str)
{
	if(ScalarConverter::is_float(str))
	{
		float num = std::strtof(str.c_str(), NULL);
		if((num < 32 || num > 127) || (str.substr(0) == "nanf" || str.substr(0) == "inff") || (str.substr(0) == "nan" || str.substr(0) == "inf") || (str.substr(0) == "+nanf" || str.substr(0) == "+inff") || (str.substr(0) == "-nan" || str.substr(0) == "-inf"))
		{
			std::cout << "char : impossible\n";
			std::cout << "int : impossible\n";
		}
		else
		{
			std::cout <<"char : '" << static_cast<char>(num) << "'" << std::endl;
			std::cout <<"int : " << static_cast<int>(num) << std::endl;
		}
		std::cout << std::fixed << std::setprecision(1) << "float : " << static_cast<float>(num) << "f" << std::endl;
		std::cout <<"double : " << static_cast<double>(num) << std::endl;
	}
	else if (ScalarConverter::is_int(str))
	{
		long num = std::strtol(str.c_str(), NULL, 10);
		if(num < 32 || num > 127)
		{
			std::cout << "char : impossible\n";
		}
		else
			std::cout <<"char : '" << static_cast<char>(num) << "'" << std::endl;
		std::cout << "int : " << num << std::endl;
		std::cout << "float : " << num<< ".0f" << std::endl;
		std::cout << "double : " << num << ".0" << std::endl;
	}
	else if(ScalarConverter::is_double(str))
	{
		double num = std::strtof(str.c_str(), NULL);
		if((num < 32 || num > 127))
			std::cout << "char : impossible\n";
		else
			std::cout <<"char : " << static_cast<char>(num) << std::endl;
		std::cout <<"int : " << static_cast<int>(num) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float : " << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double :" << num << std::endl;
	}

	else if(ScalarConverter::is_char(str))
	{
		if(!std::isprint(str[0]))
		{
			std::cout << "char : impossible"<< std::endl;
		}
		else
		{
			std::cout << "char : '" << str[0] << "'"<< std::endl;
		}
		std::cout << "int : " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float : " << static_cast<float>(str[0]) << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(str[0]) << ".0" << std::endl;
	}
}

bool ScalarConverter::is_float(const std::string &str)
{
	bool dot = false;
	unsigned long i = 0;
	if(str.empty())
		return false;
	while(str[i] == '-' || str[i] == '+')
		i++;
	if (str.substr(i) == "nanf" || str.substr(i) == "inff")
		return true;
	if (str.substr(i) == "nan" || str.substr(i) == "inf")
		return true;
	if(i == str.length())
		return false;
	while(i < str.length() - 1)
	{
		if(str[i] == '.')
		{
			if(dot == false)
				dot = true;
			else
				return false;
			i++;
		}
		if(!std::isdigit(str[i]))
			return false;
		i++;
	}
	if(str[i] != 'f')
		return false;
	float num = std::strtof(str.c_str(),NULL);
	if(num < std::numeric_limits<float>::min() || num > std::numeric_limits<float>::max())
		return false;
	return true;
}

bool ScalarConverter::is_double(const std::string &str)
{
	bool dot = false;
	unsigned long i = 0;
	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;
	if(str.empty())
		return false;
	while(str[i] == '-' || str[i] == '+')
		i++;
	if(i == str.length())
		return false;
	while(i < str.length())
	{
		if(str[i] == '.')
		{
			if(dot == false)
			{
				dot = true;
				i++;
			}
			else
				return false;
		}
		if(!std::isdigit(str[i]))
			return false;
		i++;
	}
	long num = std::strtol(str.c_str(),NULL, 10);
	if(num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		return false;
	return true;
}
