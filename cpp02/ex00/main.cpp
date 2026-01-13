#include "Fixed.hpp"

// Orthodox Canonical Formc




int main(void)
{
    Fixed a; // Default constructor
    Fixed b(a); // Copy constructor
    Fixed c; // Default constructor
    c = b = a;  // Copy assignment operator
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}
