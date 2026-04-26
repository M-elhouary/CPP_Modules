#include <iostream>
#include <stdexcept>
#include <string>



class Bad {
private:
    int* data;

public:
    // no copy constructor, copy assignment operator
    
    Bad(int val) {
        data = new int(val);
    }

    ~Bad() {
        delete data;
    }

    void setData(int val) {
        *data = val;
    }

    void print() {
        std::cout << "Value: " << *data << std::endl;
    }
};

void corruptMemory(Bad b) {
    b.setData(999); // Modifies the same memory as original object (shallow copy)
}

int main() {
    Bad obj(10);
    corruptMemory(obj);  // Triggers copy constructor (shallow copy)

    obj.print(); // Data has been changed

    // When both obj and b go out of scope, both destructors try to delete same pointer
}
