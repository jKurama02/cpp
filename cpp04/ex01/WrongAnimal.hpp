#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(std::string _type);
		WrongAnimal(const WrongAnimal& other); // Copy constructor
		WrongAnimal& operator=(const WrongAnimal& other); // Assignment operator
		~WrongAnimal();

		std::string getType();
		
		void makeSound();
};

#endif
