#include "Bureaucrat.hpp"



// file and c string 
// vtablle and virtual functions
// const and non const member functions
// inheritance and composition
// what is the difference between a copy constructor and an assignment operator in C++, and when are they called?
// pointer to member functions and how to use them
// declareing the << operator as a friend function in the Bureaucrat class, and how does it allow us to access private members of the class when overloading the operator?
// memory management and the rule of three (or five) in C++, and how it applies to the Bureaucrat class with its copy constructor, assignment operator, and destructor.

int main()  
{
    try
    {
        Bureaucrat b1("Alice", 151);
        std::cout << b1 << std::endl; 
        b1.incrementGrade(); 
        std::cout << b1 << std::endl; 
        b1.decrementGrade();
        std::cout << b1 << std::endl; 

        // Bureaucrat b2("Bob", 1);
        // std::cout << b2 << std::endl;
        // std::cout << b2 << std::endl;
        // Bureaucrat b3("Charlie", 151); 
        // b2.decrementGrade();
        // std::cout << b3 << std::endl;
    }
    catch (const std::exception& s)
    {
        std::cerr << "Exception caught: " << s.what() << std::endl;
    }
    return 0;

};
    