#ifndef BASE_HPP
#define BASE_HPP


class Base
{
public:
    virtual ~Base() {}
    virtual void generate() = 0; // Pure virtual function to make Base an abstract class
};

#endif