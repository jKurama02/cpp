#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>

static void printVector(const std::string &label, const std::vector<int> &v)
{
	std::cout << label;
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	PmergeMe app;
	try
	{
		app.parseInput(argc, argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	printVector("Before: ", app.getVec());

	struct timeval t1, t2;

	gettimeofday(&t1, NULL);
	app.sortVector();
	gettimeofday(&t2, NULL);
	double timeVec = (t2.tv_sec - t1.tv_sec) * 1000000.0 + (t2.tv_usec - t1.tv_usec);

	gettimeofday(&t1, NULL);
	app.sortDeque();
	gettimeofday(&t2, NULL);
	double timeDeq = (t2.tv_sec - t1.tv_sec) * 1000000.0 + (t2.tv_usec - t1.tv_usec);

	printVector("After: ", app.getVec());

	std::cout << "Time to process a range of " << app.getVec().size()
		<< " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << app.getDeq().size()
		<< " elements with std::deque : " << timeDeq << " us" << std::endl;

	return (0);
}
