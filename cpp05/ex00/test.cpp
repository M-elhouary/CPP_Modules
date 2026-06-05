#include <iostream>
#include <string>


//   abstract class 

class base 
{
    public:
       virtual void f() = 0;
       ~base() {};
};


int main()
{
    base b;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}