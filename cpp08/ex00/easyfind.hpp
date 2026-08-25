#ifndef EASYFIND_HPP
# define EASYFIND_HPP


#include <iostream>
#include <vector> // for vector
#include <list> // for list
#include <algorithm> // for std::find
#include <stdexcept> // for std::runtime_error

// this is a template function that takes a container and an integer n as parameters
template<typename T>
// it returns an iterator to the first occurrence of n in the container
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::runtime_error("not found");
	return it;
}

#endif
