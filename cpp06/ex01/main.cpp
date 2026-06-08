
#include <iostream>
#include "Serializer.hpp"

struct mystruct
{
	int x;
	int y;
	char c;
	bool b;
};

int main()
{

	mystruct s;

	// Assigning values
	s.x = 5;
	s.y = 10;
	s.c = 'a';
	s.b = true;

	std::cout << "Size of mystruct: " << sizeof(s) << " bytes" << std::endl;

	Data *data = new Data;
	data->s1 = "hello";
	data->n = 42;
	data->s2 = "world";

	uintptr_t raw = Serializer::serialize(data);
	Data *data2 = Serializer::deserialize(raw);

	std::cout << sizeof(uintptr_t) << std::endl;
	std::cout << sizeof(bool) << std::endl;
	std::cout << sizeof(char) << std::endl;
	std::cout << sizeof(int) << std::endl;
	// pointer to data
	std::cout << "pointer to data: " << data << std::endl;
	// unintptr_t
	std::cout << "uintptr_t: " << raw << std::endl;
	// pointer to data2
	std::cout << "pointer to data2: " << data2 << std::endl;

	std::cout << "\n"
			  << std::endl;

	std::cout << "----------------before deserialization-----------" << std::endl;
	std::cout << "data->s1: " << data->s1 << std::endl;
	std::cout << "data->n: " << data->n << std::endl;
	std::cout << "data->s2: " << data->s2 << std::endl;

	std::cout << "----------------after deserialization-----------" << std::endl;

	std::cout << "data2->s1: " << data2->s1 << std::endl;
	std::cout << "data2->n: " << data2->n << std::endl;
	std::cout << "data2->s2: " << data2->s2 << std::endl;

	data2->s1 = "hi";
	std::cout << "\n"
			  << std::endl;
	std::cout << "----------------after changing data2->s1-----------" << std::endl;
	std::cout << "data->s1: " << data->s1 << std::endl;
	std::cout << "data2->s1: " << data2->s1 << std::endl;

	std::cout << "\n"
			  << std::endl;
	std::cout << data << std::endl;
	std::cout << data2 << std::endl;

	delete data;
	return 0;
}
