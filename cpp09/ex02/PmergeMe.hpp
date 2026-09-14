#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

		void insertionSortVec(std::vector<int> &v, int val) const;
		void insertionSortDeq(std::deque<int> &d, int val) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void parseInput(int argc, char **argv);
		void sortVector();
		void sortDeque();

		const std::vector<int> &getVec() const;
		const std::deque<int> &getDeq() const;
};

#endif
