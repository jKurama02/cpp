#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
		_stack = src._stack;
	return (*this);
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string &token) const
{
	if (token.empty())
		return (false);
	for (size_t i = 0; i < token.size(); i++)
	{
		if (!isdigit(static_cast<unsigned char>(token[i])))
			return (false);
	}
	return (true);
}

double RPN::applyOperator(double a, double b, const std::string &op) const
{
	if (op == "+")
		return (a + b);
	if (op == "-")
		return (a - b);
	if (op == "*")
		return (a * b);
	if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error");
		return (a / b);
	}
	throw std::runtime_error("Error");
}

double RPN::evaluate(const std::string &expression)
{
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (isNumber(token))
		{
			if (token.size() > 1)
				throw std::runtime_error("Error");
			_stack.push_back(std::atof(token.c_str()));
		}
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			double b = _stack.back();
			_stack.pop_back();
			double a = _stack.back();
			_stack.pop_back();
			_stack.push_back(applyOperator(a, b, token));
		}
		else
			throw std::runtime_error("Error");
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	return (_stack.back());
}
