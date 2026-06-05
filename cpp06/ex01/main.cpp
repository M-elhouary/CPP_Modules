
#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data *data = new Data;
	data->s1 = "hello";
	data->n = 42;
	data->s2 = "world";

	uintptr_t raw = Serializer::serialize(data);
	Data *data2 = Serializer::deserialize(raw);

	std::cout << "data: " << data << std::endl;
	std::cout << "data2: " << data2 << std::endl;

	std::cout << "data->s1: " << data->s1 << std::endl;
	std::cout << "data->n: " << data->n << std::endl;
	std::cout << "data->s2: " << data->s2 << std::endl;

	std::cout << "data2->s1: " << data2->s1 << std::endl;
	std::cout << "data2->n: " << data2->n << std::endl;
	std::cout << "data2->s2: " << data2->s2 << std::endl;

	delete data;
	return 0;
}
