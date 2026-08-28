
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

	// Check if there are at least two numbers in the vector
	if (_v.size() < 2)
		throw std::runtime_error("not enough numbers");
<<<<<<< HEAD

		// Create a copy of the vector and sort it
	std::vector<int> tmp = _v;
	// Sort the copy of the vector
	std::sort(tmp.begin(), tmp.end());
	// Calculate the minimum difference between adjacent elements
	int min = tmp[1] - tmp[0];
	// Iterate through the sorted vector to find the shortest span
	for (size_t i = 2; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
=======
	std::vector<int> tmp(_v);
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
	return *std::min_element(tmp.begin() + 1, tmp.end());
>>>>>>> 0c0834f54ea6b220b7764a6d80a4f8e832f74b0c
}

long Span::longestSpan() const
{
	// Check if there are at least two numbers in the vector
	if (_v.size() < 2)
		throw std::runtime_error("not enough numbers");
<<<<<<< HEAD
	// Calculate the longest span by finding the difference between the maximum and minimum elements in the vector
	return *std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end());
=======
	return static_cast<long>(*std::max_element(_v.begin(), _v.end())) -
	       static_cast<long>(*std::min_element(_v.begin(), _v.end()));
>>>>>>> 0c0834f54ea6b220b7764a6d80a4f8e832f74b0c
}
