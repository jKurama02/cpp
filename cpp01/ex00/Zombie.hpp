#include <iostream>
#include <string>

class Zombie {
	private:
		std::string _name;
	public:
		Zombie(std::string name)
		{
			_name = name;
		};
		void announce();
		~Zombie()
		{
			std::cout << _name << " is dead" << std::endl;
		}
};

