
#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const &src)
{
	*this = src;
}

Span::~Span() {}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_v = rhs._v;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_v.size() >= _n)
		throw std::runtime_error("Span is full");
	_v.push_back(n);
}

int Span::shortestSpan() const
{
	if (_v.size() < 2)
		throw std::runtime_error("not enough numbers");
	std::vector<int> tmp(_v);
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
	return *std::min_element(tmp.begin() + 1, tmp.end());
}

long Span::longestSpan() const
{
	if (_v.size() < 2)
		throw std::runtime_error("not enough numbers");
	return static_cast<long>(*std::max_element(_v.begin(), _v.end())) -
	       static_cast<long>(*std::min_element(_v.begin(), _v.end()));
}
