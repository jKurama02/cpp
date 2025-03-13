#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		WrongCat(std::string _type);
		WrongCat(const WrongCat& another);
		WrongCat& operator=(const WrongCat& other);
		~WrongCat();

		void virtual makeSound();

};
