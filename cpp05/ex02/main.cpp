#include <iostream>
#include <stdexcept>
#include <string>

using namespace std ;


class base
{
public:
    virtual void    f() = 0 ;       
};


class derived : public base {

    public:
    void f()
    {
        cout << "test" << std::endl;
    }
};

int main()
{
    // base *b = new derived();
    derived b;
    b.f() ;

    void** vptr = *(void***)(&b) ;

    cout <<   "vptr: " << vptr << endl ;
    cout << "object address: " << &b << endl ;
    return 0 ;
}