#include <iostream>
#include <cctype>

int main(int argc , char **argv)
{
	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		int i = 0;
		int z = 1;
		while(z < argc)
		{
			while(argv[z][i] && z <= argc)
			{
				std::cout << (char)toupper(argv[z][i]);
				i++;
			}
			z++;
			i = 0;
		}
		std::cout << std::endl;
	}
	return 0;
}
