#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
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
		void print_table()
		{
				std::cout << "---------------------------------------------\n";
				std::cout << "|  Index  |First Name|Last Name | Nickname |\n";
				std::cout << "---------------------------------------------\n";
				int k = 0;
				while(k < contactsCount)
				{
					contacts[k].printContactShort(contacts[k]);
					k++;
				}
		};

		void search_contact()
		{
			print_table();
			std::string input;
			std::cout << "Enter the index of the contact: ";
			std::getline(std::cin, input);
			int value = atoi(input.c_str());
			std::cout << "contactsCount : " << contactsCount << "\n";
			std::cout << "value : " << value << "\n";

 			if((value < 0 || value > 7) || value >= contactsCount)
			{
				std::cout << "Invalid index\n";
				return;
			}
			else
			{
			std::cout << "First Name: " << contacts[value].getFirstName() << "\n";
			std::cout << "Last Name: " << contacts[value].getLastName() << "\n";
			std::cout << "Nickname: " << contacts[value].getNickname() << "\n";
			std::cout << "Phone Number: " << contacts[value].getPhoneNumber() << "\n";
			std::cout << "Darkest Secret: " << contacts[value].getDarkestSecret() << "\n";
			}
		}
		void addContact()
		{
			Contact newContact;

			if(contactsCount == 8)
			{
				std::string input;
				std::cout << "PhoneBook is full, do you wanto to cancell the oldest contact ?\n";
				std::getline(std::cin, input);
				if("y" == input || "Y" == input)
				{
					for(int i = 0; i < 7; i++)
					{
						contacts[i] = contacts[i + 1];
						contacts[i].setId(i);
					}
					contactsCount--;
					contacts[7] = newContact;
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
				print_table();
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
