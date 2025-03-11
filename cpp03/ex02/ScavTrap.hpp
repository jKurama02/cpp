#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		bool _gate;
	public:
	// Costruttori e distruttore
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(ScavTrap& other);
	~ScavTrap();

	// Metodi sovrascritti
	void attack(const std::string target);

	// Metodo specifico di ScavTrap
	void guardGate();
};

#endif
