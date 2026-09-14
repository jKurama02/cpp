#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <vector>

class RPN
{
	private:
		std::vector<double> _stack;

		bool isOperator(const std::string &token) const;
		bool isNumber(const std::string &token) const;
		double applyOperator(double a, double b, const std::string &op) const;

	public:
		RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN();

		double evaluate(const std::string &expression);
};

#endif
