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
		if(!std::getline(std::cin, command))
		{
			return 0;
		}
		if("ADD" == command || "add" == command)
		{
			phoneBook.addContact();
		}
			else if("SEARCH" == command || "search" == command)
		{
			phoneBook.search_contact();
		}
		else if("EXIT" == command || "exit" == command)
		{
			std::cout << "EXIT\n";
			return 0;
		}
		else
		{
			std::cout << "Invalid command\n";
		}
	}
	return 0;
}
