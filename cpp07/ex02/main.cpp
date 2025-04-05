#include "Array.hpp"


int main() {
	// Test costruzione di default
	Array<int> arr1;
	std::cout << "Dimensione arr1: " << arr1.size() << std::endl;

	// Test costruzione con dimensione
	Array<int> arr2(5);
	std::cout << "Dimensione arr2: " << arr2.size() << std::endl;
	arr2[0] = 10;
	std::cout << "arr2[0]: " << arr2[0] << std::endl;

	// Test copia costruzione
	Array<int> arr3 = arr2;
	std::cout << "Dimensione arr3: " << arr3.size() << std::endl;
	std::cout << "arr3[0]: " << arr3[0] << std::endl;

	// Test operatore di assegnazione
	Array<int> arr4;
	arr4 = arr2;
	std::cout << "Dimensione arr4: " << arr4.size() << std::endl;
	std::cout << "arr4[0]: " << arr4[0] << std::endl;

	// Test eccezione
	try {
		std::cout << arr1[0] << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Eccezione: " << e.what() << std::endl;
	}

	return 0;
}
