#include "Fixed.hpp"


// fixed point  && overload



int main(void)
{
    Fixed a; // Default constructor
    Fixed const b(10); // Int constructor 
    Fixed const c(42.42f); // Float constructor
    Fixed const d(b); // Copy constructor
    a = Fixed(1234.4321f); // Copy assignment operator


    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    // toInt 
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}