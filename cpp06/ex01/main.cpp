#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	const int i = 5;
	Data Cubo = Data(i);

	uintptr_t Triangolo = Serializer::serialize(&Cubo);

	Data * Palla = Serializer::deserialize(Triangolo);

	std::cout << &Cubo << std::endl;
	std::cout << Triangolo << std::endl;
	std::cout << Palla << std::endl;
	std::cout << &Palla << std::endl;
}
