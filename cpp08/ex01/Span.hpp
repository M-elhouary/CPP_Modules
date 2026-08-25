
#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>
# include <numeric>
# include <iterator>
#include <list>
#include <cstdlib>
#include <iostream>

class Span
{
	private:
		std::vector<int> _v;
		unsigned int _n;

	public:
		Span(unsigned int n);
		Span(Span const &src);
		~Span();
		Span &operator=(Span const &rhs);

		void addNumber(int n);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename Iterator>
		void addRange(Iterator first, Iterator last)
		{
			if (static_cast<unsigned int>(std::distance(first, last)) > _n - _v.size())
				throw std::runtime_error("Span is full");
			while (first != last)
			{
				addNumber(*first);
				++first;
			}
		}
};

#endif
