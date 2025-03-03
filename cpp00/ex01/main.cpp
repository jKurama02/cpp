#include"contact.hpp"
#include"phonebook.hpp"

int main()
{
	std::string command;
	PhoneBook phoneBook;

	std::cout << "Welcome to My Awesome PhoneBook!\n";
	while(true)
	{
		std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if("ADD" == command)
		{
			phoneBook.addContact();
		}
			else if("SEARCH" == command)
		{
			std::cout << "chose SEARCH\n";
		}
		else if("EXIT" == command)
		{
			std::cout << "chose EXIT\n";
		}
		else
		{
			std::cout << "Invalid command\n";
		}
	}
	return 0;
}
