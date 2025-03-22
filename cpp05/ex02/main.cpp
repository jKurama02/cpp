#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
		// Create bureaucrats with different grades
		Bureaucrat highRank("Boss", 1);
		Bureaucrat mediumRank("Manager", 50);
		Bureaucrat lowRank("Intern", 12);

		// Create different forms
		ShrubberyCreationForm shrubForm("garden");
		RobotomyRequestForm robotForm("R2D2");
		PresidentialPardonForm pardonForm("Arthur Dent");

		std::cout << "\n--- Testing ShrubberyCreationForm ---\n" << std::endl;

		// Try signing with different bureaucrats
		lowRank.signForm(shrubForm);    // Should work (grade 140, needs 145)
		// Try executing with different bureaucrats
		lowRank.executeForm(shrubForm); // Should work (grade 140, needs 137)

		std::cout << "\n--- Testing RobotomyRequestForm ---\n" << std::endl;

		// Try signing with different bureaucrats
		lowRank.signForm(robotForm);    // Should fail (grade 140, needs 72)
		mediumRank.signForm(robotForm); // Should work (grade 50, needs 72)

		// Try executing with different bureaucrats
		mediumRank.executeForm(robotForm); // Should work (grade 50, needs 45)

		std::cout << "\n--- Testing PresidentialPardonForm ---\n" << std::endl;

		// Try signing with different bureaucrats
		mediumRank.signForm(pardonForm);  // Should fail (grade 50, needs 25)
		highRank.signForm(pardonForm);    // Should work (grade 1, needs 25)

		// Try executing with different bureaucrats
		mediumRank.executeForm(pardonForm); // Should fail (grade 50, needs 5)
		highRank.executeForm(pardonForm);   // Should work (grade 1, needs 5)

		// Try executing without signing first
		ShrubberyCreationForm unsignedForm("unsignedTest");
		highRank.executeForm(unsignedForm); // Should fail (not signed)

	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
