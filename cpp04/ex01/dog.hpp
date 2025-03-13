#include "animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* brain;
	public :
		Dog();
		Dog(std::string _type);
		Dog(const Dog& another);
		Dog& operator=(const Dog& other);
		~Dog();

		void virtual makeSound();

};
