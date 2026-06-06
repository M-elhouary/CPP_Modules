#include <iostream>
#include <iomanip>

int main(int argc, char *argv[])
{
    char i = 'a';

    double d = static_cast<double>(argv[1][0]);

    std::cout << "Integer value: " << i << std::endl;
    std::cout << "Double value: "
              << std::fixed
              << std::setprecision(1)
              << d
              << std::endl;
}