#include <iostream>
#include <string>
#include <cctype>
#include "contact.hpp"

#ifndef PHONEBOOK
#define PHONEBOOK


class PhoneBook
{
	private:
		Contact contacts[8];
		int contactsCount;

	public:
		PhoneBook()
		{
			contactsCount = 0;
		}
		void addContact()
		{
			Contact newContact;

			// Check if the phonebook is full se lavora correttamente
			if(contactsCount == 4)
			{
				std::cout << "PhoneBook is full, do you wanto to cancell the oldest contact ?\n";
				std::string input;
				std::getline(std::cin, input);
				if("y" == input || "Y" == input)
				{
					for(int i = 0; i < 3; i++)
					{
						contacts[i] = contacts[i + 1];
					}
					contacts[3] = newContact;
				}
				else if("n" == input || "N" == input)
				{
					std::cout << "Contact not saved\n";
					return;
				}
				else
				{
					std::cout << "Invalid input\n";
					return;
				}
			}
			//
			newContact.setId(contactsCount);
			std::string input;
			std::cout << "Enter first name: ";
			std::getline(std::cin, input);
			newContact.setFirstName(input);
			std::cout << "Enter last name: ";
			std::getline(std::cin, input);
			newContact.setLastName(input);
			std::cout << "Enter nickname: ";
			std::getline(std::cin, input);
			newContact.setNickname(input);
			std::cout << "Enter phone number: ";
			std::getline(std::cin, input);
			newContact.setPhoneNumber(input);
			std::cout << "Enter darkest secret: ";
			std::getline(std::cin, input);
			newContact.setDarkestSecret(input);
			contacts[contactsCount] = newContact;
			contactsCount++;
			std::cout << "Do you want to print the contact? (Y/N): ";
			std::getline(std::cin, input);
			if("y" == input || "Y" == input)
			{
				std::cout << "---------------------------------------------\n";
				std::cout << "|  Index  |First Name|Last Name | Nickname |\n";
				std::cout << "---------------------------------------------\n";
				int k;
				while(k < contactsCount)
				{
					contacts[k].printContactShort(contacts[k]);
					k++;
				}
			}
			else if("n" == input || "N" == input)
			{
				std::cout << "Contact saved\n";
			}
			else
			{
				std::cout << "Invalid input\n";
			}
		}
};

#endif
