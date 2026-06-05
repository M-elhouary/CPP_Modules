<<<<<<< HEAD

#include <iostream>
#include <cstdlib>
=======
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
>>>>>>> 82b0676e7b45d3dfd0f154efa2316bbc5dde1bf3
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
<<<<<<< HEAD
	int i = rand() % 3;
	if (i == 0)
		return new A;
	if (i == 1)
		return new B;
	return new C;
=======
    int i = std::rand() % 3;
    if (i == 0)
        return new A();
    else if (i == 1)
        return new B();
    else
        return new C();
>>>>>>> 82b0676e7b45d3dfd0f154efa2316bbc5dde1bf3
}

void identify(Base* p)
{
<<<<<<< HEAD
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
=======
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
>>>>>>> 82b0676e7b45d3dfd0f154efa2316bbc5dde1bf3
}

void identify(Base& p)
{
<<<<<<< HEAD
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &e) {}
=======
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(const std::exception& e) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(const std::exception& e) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(const std::exception& e) {}
>>>>>>> 82b0676e7b45d3dfd0f154efa2316bbc5dde1bf3
}

int main()
{
<<<<<<< HEAD
	srand(time(NULL));
	Base *p = generate();
	identify(p);
	identify(*p);
	delete p;
	return 0;
=======
    std::srand(std::time(0));

    for (int i = 0; i < 10; ++i)
    {
        Base* p = generate();
        std::cout << "Pointer identify: ";
        identify(p);
        std::cout << "Reference identify: ";
        identify(*p);
        delete p;
        std::cout << "----------------" << std::endl;
    }

    return 0;
>>>>>>> 82b0676e7b45d3dfd0f154efa2316bbc5dde1bf3
}
