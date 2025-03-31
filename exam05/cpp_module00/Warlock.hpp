#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include <string>
//________https://github.com/THE-Bandersnatch/EXAM-CPP/blob/master/examRank05/cpp_module00/Warlock.hpp
// sto tizio mette il costruttore di copia e di assegnazione privati
class Warlock
{
	private:
		std::string name;
		std::string title;

	public:
		Warlock();
		Warlock(std::string n, std::string t);
		Warlock(const Warlock& other);
		Warlock& operator=(const Warlock& other);
		~Warlock();

		const std::string& getName() const;
		const std::string& getTitle() const;

		void introduce() const;

		void setTitle(const std::string& string) ;
		void setName(const std::string& string);
};


#endif
//=const= alla fiene delle dichiarazioni dei metodi
