#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(std::string _type);
		Animal(const Animal& other); // Copy constructor
		Animal& operator=(const Animal& other); // Assignment operator
		virtual ~Animal();

		std::string getType();

		virtual void makeSound() const = 0;

};
#endif
