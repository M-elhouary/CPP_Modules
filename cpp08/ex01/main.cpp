
#include "Span.hpp"

static void subjectExample()
{
	std::cout << "--- subject example ---" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void exceptions()
{
	std::cout << "--- exceptions ---" << std::endl;
	try
	{
		Span sp(1);
		sp.addNumber(42);
		sp.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "one element: " << e.what() << std::endl;
	}
	try
	{
		Span sp(3);
		sp.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "empty span: " << e.what() << std::endl;
	}
	try
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (const std::exception &e)
	{
		std::cout << "full span: " << e.what() << std::endl;
	}
}

static void bigSpan()
{
	std::cout << "--- 10000+ numbers ---" << std::endl;
	Span sp(15000);
	std::vector<int> v;
	for (int i = 0; i < 12000; i++)
		v.push_back(std::rand() % 1000000);
	sp.addRange(v.begin(), v.end());
	sp.addRange(v.begin(), v.begin() + 2000); // list iterators work too

	std::list<int> l;
	l.push_back(-50000);
	l.push_back(2000000000);
	sp.addRange(l.begin(), l.end());

	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(0); // full now
	}
	catch (const std::exception &e)
	{
		std::cout << "overflow after range fill: " << e.what() << std::endl;
	}
}

int main()
{
	subjectExample();
	exceptions();
	bigSpan();
	return 0;
}
