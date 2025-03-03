#include <iostream>
#include <string>
#include <cctype>

#ifndef CONTACT
#define CONTACT

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
		int id;
	public:
		void setId(int id)
		{
			this->id = id;
		}
		void setFirstName(std::string name)
		{
			firstName = name;
		}
		void setLastName(std::string name)
		{
			lastName = name;
		}
		void setNickname(std::string name)
		{
			nickname = name;
		}
		void setPhoneNumber(std::string number)
		{
			phoneNumber = number;
		}
		void setDarkestSecret(std::string secret)
		{
			darkestSecret = secret;
		}
		int getId() { return id; }
		std::string getFirstName() const { return firstName; }
		std::string getLastName() const { return lastName; }
		std::string getNickname() const { return nickname; }
		std::string getPhoneNumber() const { return phoneNumber; }
		std::string getDarkestSecret() const { return darkestSecret; }
		void printContactShort(Contact contatto)
		{

			std::cout <<"|        " << id << "|";
			contatto.display_field(firstName);
			contatto.display_field(lastName);
			contatto.display_field(nickname);
			std::cout << "\n";
		}

		void display_field(std::string field)
		{
			if (field.size() > 10)
			{
				std::cout << field.substr(0, 9) << ".";
			}
			else
			{
				int i = 0;
				while  ((i + field.size()) < 10)
				{
					 std::cout << " ";
					 i++;
				}
				std::cout << field;
			}
			std::cout << "|";
		}

		void printContact(Contact contatto)
		{
			printContactShort(contatto);
			std::cout << "---------------------------------------------\n";
		}
};

#endif
