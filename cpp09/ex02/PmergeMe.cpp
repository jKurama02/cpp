#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		_vec = src._vec;
		_deq = src._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string token(argv[i]);
		if (token.empty())
			throw std::runtime_error("Error");
		size_t start = 0;
		if (token[0] == '+')
			start = 1;
		if (start >= token.size())
			throw std::runtime_error("Error");
		for (size_t j = start; j < token.size(); j++)
		{
			if (!isdigit(static_cast<unsigned char>(token[j])))
				throw std::runtime_error("Error");
		}
		long value = std::atol(token.c_str());
		if (value < 0 || value > 2147483647)
			throw std::runtime_error("Error");
		_vec.push_back(static_cast<int>(value));
		_deq.push_back(static_cast<int>(value));
	}
	if (_vec.empty())
		throw std::runtime_error("Error");
}

/* ---------- Binary insertion helper for vector ---------- */
void PmergeMe::insertionSortVec(std::vector<int> &v, int val) const
{
	size_t lo = 0;
	size_t hi = v.size();
	while (lo < hi)
	{
		size_t mid = lo + (hi - lo) / 2;
		if (v[mid] < val)
			lo = mid + 1;
		else
			hi = mid;
	}
	v.insert(v.begin() + lo, val);
}

/* ---------- Binary insertion helper for deque ---------- */
void PmergeMe::insertionSortDeq(std::deque<int> &d, int val) const
{
	size_t lo = 0;
	size_t hi = d.size();
	while (lo < hi)
	{
		size_t mid = lo + (hi - lo) / 2;
		if (d[mid] < val)
			lo = mid + 1;
		else
			hi = mid;
	}
	d.insert(d.begin() + lo, val);
}

/* ---------- Recursive Ford-Johnson (merge-insertion) for vector ---------- */
static std::vector<int> mergeInsertVec(const std::vector<int> &input,
	void (PmergeMe::*insertFn)(std::vector<int> &, int) const, const PmergeMe *self)
{
	if (input.size() <= 1)
		return (input);

	std::vector<int> mainChain;
	std::vector<int> pend;
	size_t i = 0;
	int leftover = 0;
	bool hasLeftover = false;

	for (; i + 1 < input.size(); i += 2)
	{
		int a = input[i];
		int b = input[i + 1];
		if (a < b)
		{
			mainChain.push_back(b);
			pend.push_back(a);
		}
		else
		{
			mainChain.push_back(a);
			pend.push_back(b);
		}
	}
	if (i < input.size())
	{
		leftover = input[i];
		hasLeftover = true;
	}

	mainChain = mergeInsertVec(mainChain, insertFn, self);

	for (size_t k = 0; k < pend.size(); k++)
		(self->*insertFn)(mainChain, pend[k]);

	if (hasLeftover)
		(self->*insertFn)(mainChain, leftover);

	return (mainChain);
}

/* ---------- Recursive Ford-Johnson (merge-insertion) for deque ---------- */
static std::deque<int> mergeInsertDeq(const std::deque<int> &input,
	void (PmergeMe::*insertFn)(std::deque<int> &, int) const, const PmergeMe *self)
{
	if (input.size() <= 1)
		return (input);

	std::deque<int> mainChain;
	std::deque<int> pend;
	size_t i = 0;
	int leftover = 0;
	bool hasLeftover = false;

	for (; i + 1 < input.size(); i += 2)
	{
		int a = input[i];
		int b = input[i + 1];
		if (a < b)
		{
			mainChain.push_back(b);
			pend.push_back(a);
		}
		else
		{
			mainChain.push_back(a);
			pend.push_back(b);
		}
	}
	if (i < input.size())
	{
		leftover = input[i];
		hasLeftover = true;
	}

	mainChain = mergeInsertDeq(mainChain, insertFn, self);

	for (size_t k = 0; k < pend.size(); k++)
		(self->*insertFn)(mainChain, pend[k]);

	if (hasLeftover)
		(self->*insertFn)(mainChain, leftover);

	return (mainChain);
}

void PmergeMe::sortVector()
{
	_vec = mergeInsertVec(_vec, &PmergeMe::insertionSortVec, this);
}

void PmergeMe::sortDeque()
{
	_deq = mergeInsertDeq(_deq, &PmergeMe::insertionSortDeq, this);
}

const std::vector<int> &PmergeMe::getVec() const
{
	return (_vec);
}

const std::deque<int> &PmergeMe::getDeq() const
{
	return (_deq);
}
