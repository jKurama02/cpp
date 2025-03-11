#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	// Test base del FragTrap
	std::cout << "--- TESTING FRAGTRAP ---\n" << std::endl;

	// Creazione di un FragTrap
	FragTrap frag("FR4G-TP");

	// Test delle funzionalità base
	frag.attack("Bandit");
	frag.takeDamage(20);
	frag.beRepaired(10);

	// Test della funzionalità speciale
	frag.highFivesGuys();

	std::cout << "\n--- TEST COMPLETED ---" << std::endl;

	return 0;
}
