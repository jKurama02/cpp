#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iterator>
# include <exception>

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int n);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			if (_numbers.size() + std::distance(begin, end) > _maxSize)
				throw (Span::FullException());
			_numbers.insert(_numbers.end(), begin, end);
		}

		class FullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		Span();

		unsigned int		_maxSize;
		std::vector<int>	_numbers;
};

#endif