#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()


Base * generate(void)
{
    int random = rand() % 3; // Generate a random number between 0 and 2

    if (random == 0)
        return new A(); // Return an instance of class A
    else if (random == 1)
        return new B(); // Return an instance of class B
    else
        return new C(); // Return an instance of class C
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "Generated an instance of class A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "Generated an instance of class B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "Generated an instance of class C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {}
}




int main()
{
    srand(time(NULL)); // Seed the random number generator

    Base* obj = generate();
    Base &ref = *obj; // Generate a random object of type A, B, or C

    identify(obj); // Identify the type of the generated object using pointer
    identify(ref); // Identify the type of the generated object using reference
    delete obj; // Clean up the allocated object
    return 0;
}   