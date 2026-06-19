#include <iostream>
#include <string>



class base {

    public:
        virtual void  print()
        {
            std::cout << "base class" << std::endl;
        }
};


class derrived : public base {

    public:
        void print()
        {
            std::cout << "derrived class"  << std::endl;
        }

};




int main()
{

    base* a = new base();
    derrived* b = dynamic_cast<derrived*>(a);
    if(b)
        std::cout << "dynamic_cast success" << std::endl;
    else
        std::cout << "dynamic_cast failed" << std::endl;
    a->print();
    b->print();
    return 0;
}


