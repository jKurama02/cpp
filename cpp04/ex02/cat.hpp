#include "animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* brain;
	public :
		Cat();
		Cat(std::string _type);
		Cat(const Cat& another);
		Cat& operator=(const Cat& other);
		~Cat();

		void makeSound() const;

};
