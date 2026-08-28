#include "easyfind.hpp"

int main()
{

	// list container test
	std::list<int> list;
	for(int i = 0; i < 10; i++)
		list.push_back(i);
	try
	{
		std::cout << *easyfind(list, 6) << std::endl;
		std::cout << *easyfind(list, 11) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// vector test
	std::vector<int> vector(10);
	for(int i = 0; i < 10; i++)
		vector[i] = i;
	try
	{
		std::cout << *easyfind(vector, 7) << std::endl;
		std::cout << *easyfind(vector, 12) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0; 
}
