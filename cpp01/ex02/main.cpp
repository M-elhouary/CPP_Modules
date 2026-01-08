
#include <iostream>


int main() {

    std::string  brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &strinrRF = brain;

    std::cout << "address memory of brain is : " << &brain << std::endl;
    std::cout << "address memory of stringPTR is : " << stringPTR << std::endl;
    std::cout << "address memory of strinrRF is : " << &strinrRF << std::endl;

    std::cout << "value of brain is : " << brain << std::endl;
    std::cout << "value of stringPTR is : " << *stringPTR << std::endl;
    std::cout << "value of strinrRF is : " << strinrRF << std::endl;

}

