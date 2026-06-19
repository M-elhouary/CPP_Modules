#include <iostream>
#include <string>
#include <cstdio>


class base {

    public:
        virtual void print() {
            std::cout << "Base class" << std::endl;
        }
};

class derived : public base {
    
    public:
        void print() {
            std::cout << "Derived class" << std::endl;
        }
};



int main()
{
    // int v1 = 1;
    // double v2;

    // std::cout << "v1:" << v1 << std::endl;
    // std::cout << "v2:" << v2 << std::endl;

    // std::cout << " address of v2:" << &v1 << std::endl;
    // std::cout << "address of v2:" << &v2 << std::endl;

    // v2 = static_cast<double>(v1);
    
    // std::cout << "address of v1 after cast :" << &v1 << std::endl;
    // std::cout << "address of v2 after cast :" << &v2 << std::endl;

    // printf("%f\n", v2);
    // std::cout << "type of v1 : " << typeid(v1).name() << std::endl;
    // std::cout << "type of v2 : " << typeid(v2).name() << std::endl;



    // unrelated pointer type 
    // char* c = "a";
    // int* c1 ;

    // c1 = static_cast<int*>(c);
    // std::cout << "c : " << *c << std::endl;
    // std::cout << "c1 : " << c1 << std::endl;


    base* a = new base();
    a->print();


    
    base* b = new derived();
    b->print();
    
    //Downcasting
    derived* d = static_cast<derived*>(b);
    d->print();

    
    
    // Upcasting
    base* d2 = static_cast<base*>(d);
    d2->print();
    
    delete b;
    return 0;

}