
#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>
# include <numeric>

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
		int shortestSpan();
		int longestSpan();
};

#endif
