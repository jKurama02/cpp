#include "animal.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(std::string _type);
		Dog(const Dog& another);
		Dog& operator=(const Dog& other);
		~Dog();
		
		void virtual makeSound();

};
