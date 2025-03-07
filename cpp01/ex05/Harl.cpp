#include "Harl.hpp"

void Harl::DEBUG(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
};

void Harl::INFO(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
};
void Harl::ERROR(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
};

void Harl::WARNING(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
};

void Harl::complain(std::string level)
{
	std::string in[4] = {"1", "2", "3", "4"};
	if(level == in[0] || level == in[1] || level == in[2] || level == in[3])
	{
		if (level == "1")
			DEBUG();
		else if (level == "2")
			INFO();
		else if (level == "3")
			ERROR();
		else if (level == "4")
			WARNING();
	}
	else
		std::cout << "Invalid level" << std::endl;
}
