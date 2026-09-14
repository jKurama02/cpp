#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _db;

		bool isValidDate(const std::string &date) const;
		bool isValidValue(const std::string &value, float &out, std::string &error) const;
		std::string trim(const std::string &s) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		void loadDatabase(const std::string &filename);
		void processFile(const std::string &filename) const;
};

#endif
