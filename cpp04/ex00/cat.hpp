#include "animal.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat(std::string _type);
		Cat(const Cat& another);
		Cat& operator=(const Cat& other);
		~Cat();

		void virtual makeSound();

};
