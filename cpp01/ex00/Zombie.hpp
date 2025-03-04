#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(){};
		void set_name(std::string name)
		{
			_name = name;
		};
		void announce();
		~Zombie()
		{
			std::cout << _name << " is dead" << std::endl;
		};
};
		void randomChump( std::string name );
		Zombie *newZombie(std::string name);

