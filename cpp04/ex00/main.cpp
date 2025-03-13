#include "animal.hpp"
#include "cat.hpp"
#include "dog.hpp"
#include "WrongAnimal.hpp"

void testAnimal() {
	Animal* meta = new Animal();
	std::cout << "Animal type: " << meta->getType() << std::endl;
	meta->makeSound();
	delete meta;
}

void testDog() {
	Animal* dog = new Dog();
	std::cout << "Dog type: " << dog->getType() << std::endl;
	dog->makeSound();
	delete dog;
}

void testCat() {
	Animal* cat = new Cat();
	std::cout << "Cat type: " << cat->getType() << std::endl;
	cat->makeSound();
	delete cat;
}

void testWrongAnimal() {
	WrongAnimal wrong("gino");
	std::cout << "WrongAnimal type: " << wrong.getType() << std::endl;
	wrong.makeSound();
}

int main() {
	std::cout << "______Testing Animal class:______" << std::endl;
	testAnimal();
	std::cout << std::endl;

	std::cout << "______Testing Dog class:_________" << std::endl;
	testDog();
	std::cout << std::endl;

	std::cout << "______Testing Cat class:_________" << std::endl;
	testCat();
	std::cout << std::endl;

	std::cout << "______Testing WrongAnimal class:_" << std::endl;
	testWrongAnimal();
	std::cout << std::endl;

	return 0;
}
