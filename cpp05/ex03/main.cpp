#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	// Creazione di un Intern
	Intern someRandomIntern;
	std::cout << "//________________________________\n";
	// Creazione di un RobotomyRequestForm
	AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	// Creazione di un PresidentialPardonForm
	AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Zaphod");

	// Creazione di un ShrubberyCreationForm
	AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");

	// Tentativo di creare un form che non esiste
	AForm* nonExistent = someRandomIntern.makeForm("unknown form", "Target");
	std::cout << "//________________________________\n";

	// Test dei form creati
	Bureaucrat boss("Boss", 1); // Bureaucrat con grado massimo
	std::cout << "//________________________________\n";

	if (rrf) {
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf; // Liberare la memoria
	}
	std::cout << "//________________________________\n";

	if (ppf) {
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf; // Liberare la memoria
	}
	std::cout << "//________________________________\n";

	if (scf) {
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf; // Liberare la memoria
	}
	std::cout << "//________________________________\n";

	// Il puntatore non-esistente sarà NULL
	if (nonExistent) {
		delete nonExistent;
	}
	return 0;
}
