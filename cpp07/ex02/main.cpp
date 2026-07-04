
#include <iostream>
#include "Array.hpp"

int main()
{
	// Test with int
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i * 10;

	// Test with copy constructor and assignment operator
	Array<int> b(a);
	b[0] = 999;

	Array<int> c;
	c = a;
	c[1] = 777;
// Test with const Array
	const Array<int> constA(a);

	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << "b[" << i << "] = " << b[i] << std::endl;
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << "c[" << i << "] = " << c[i] << std::endl;
	std::cout << "constA[2] = " << constA[2] << std::endl;

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
