#include "iter.hpp"

void printInt(int i){
	std::cout << i << std::endl;}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	int len = sizeof(intArray) / 4;

	iter(intArray, len, printInt);
	return 0;
}
