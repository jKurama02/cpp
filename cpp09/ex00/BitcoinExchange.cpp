#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		_db = src._db;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &s) const
{
	size_t start = s.find_first_not_of(" \t");
	if (start == std::string::npos)
		return ("");
	size_t end = s.find_last_not_of(" \t");
	return (s.substr(start, end - start + 1));
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	return (true);
}

bool BitcoinExchange::isValidValue(const std::string &value, float &out, std::string &error) const
{
	if (value.empty())
	{
		error = "Error: bad input => empty value";
		return (false);
	}
	std::stringstream ss(value);
	float v;
	ss >> v;
	if (ss.fail() || !ss.eof())
	{
		error = "Error: bad input => " + value;
		return (false);
	}
	if (v < 0)
	{
		error = "Error: not a positive number.";
		return (false);
	}
	if (v > 1000)
	{
		error = "Error: too large a number.";
		return (false);
	}
	out = v;
	return (true);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		std::exit(1);
	}
	std::string line;
	std::getline(file, line); // skip header
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;
		std::string date = trim(line.substr(0, comma));
		std::string valueStr = trim(line.substr(comma + 1));
		if (!isValidDate(date))
			continue;
		float value = static_cast<float>(std::atof(valueStr.c_str()));
		_db[date] = value;
	}
	file.close();
}

void BitcoinExchange::processFile(const std::string &filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line); // skip header "date | value"
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t sep = line.find('|');
		if (sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = trim(line.substr(0, sep));
		std::string valueStr = trim(line.substr(sep + 1));

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		float value;
		std::string error;
		if (!isValidValue(valueStr, value, error))
		{
			std::cout << error << std::endl;
			continue;
		}

		std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
		if (it == _db.end() || it->first != date)
		{
			if (it == _db.begin())
			{
				std::cout << "Error: no earlier rate available for " << date << std::endl;
				continue;
			}
			--it;
		}
		std::cout << date << " => " << valueStr << " = " << (it->second * value) << std::endl;
	}
	file.close();
}
