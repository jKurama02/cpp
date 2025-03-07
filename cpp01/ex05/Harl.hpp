#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	private:
		void DEBUG(void);
		void INFO(void);
		void ERROR(void);
		void WARNING(void);
	public:
		void complain(std::string level);
};
#endif
