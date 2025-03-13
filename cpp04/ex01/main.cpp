#include "animal.hpp"
#include "cat.hpp"
#include "dog.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"

int main()
{
	Animal* animals[6];

	for(int i = 0; i < 3; i++)
	{
		animals[i] = new Dog();
		animals[i]->makeSound();
	}
	for(int i = 3; i < 6; i++)
	{
		animals[i] = new Cat();
		animals[i]->makeSound();
	}
	for(int i = 0; i < 6; i++)
	{
		std::cout << "Animals type is : " << animals[i]->getType() << std::endl;
	}
	for(int i = 0; i < 6; i++)
	{
		delete animals[i];
	}
	return 0;
}


