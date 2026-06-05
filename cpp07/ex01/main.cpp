
#include <iostream>
#include "iter.hpp"

void print(int const &i)
{
	std::cout << i << std::endl;
}

int main()
{
	int tab[] = {0, 1, 2, 3, 4};
	iter(tab, 5, print);
	return 0;
}
