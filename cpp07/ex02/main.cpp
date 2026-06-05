
#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	try
	{
		std::cout << a[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
