#include <iostream>
#include <iomanip>

int main()
{
    int i = 1;

    double d = static_cast<double>(i);

    std::cout << "Integer value: " << i << std::endl;
    std::cout << "Double value: "
              << std::fixed
              << std::setprecision(1)
              << d
              << std::endl;
}