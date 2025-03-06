#include <iostream>
#include <string>
#include <fstream>

std::string all_replace(std::string riri, std::string s1, std::string s2)
{
	std::string result;
	size_t start_p = 0;
	size_t first_occ;
	(void)s2;

	while((first_occ = riri.find(s1, start_p)) != std::string::npos)
	{
		result.append(riri, start_p, first_occ - start_p);
		result.append(s2);
		start_p = first_occ + s1.length();
	}
	result.append(riri, start_p, riri.length() - start_p);

	return (result);

}

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		std::cout << "wrong argc number \n";
		return 1;
	}
	else
	{
		std::string riga;
		std::string nuovo_file;

		std::fstream first_file(argv[1], std::ios::in);
		if(!first_file)
		{
			std::cout << "err: file not exist \n";
			return 1;
		}

		nuovo_file = std::string(argv[1]) + ".replace.txt";
		std::fstream second_file(nuovo_file.c_str(), std::ios::out | std::ios::in | std::ios::app);

		while(std::getline(first_file, riga))
		{
			second_file << all_replace(riga, argv[2], argv[3]) << std::endl;
		}

		first_file.close();
		second_file.close();
		return 0;
	}
}
