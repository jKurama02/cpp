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
		Animal(const Animal& other); // Costruttore di copia
		Animal& operator=(const Animal& other); // Operatore di assegnazione
		~Animal();
};	
#endif
