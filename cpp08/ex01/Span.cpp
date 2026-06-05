
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

int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw std::runtime_error("not enough numbers");
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (size_t i = 2; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (_v.size() < 2)
		throw std::runtime_error("not enough numbers");
	return *std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end());
}
