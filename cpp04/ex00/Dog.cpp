#include "Dog.hpp"

// Default constructor
Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

// Assignment operator
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}
// Destructor
Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}
// makeSound method
void Dog::makeSound() const
{
    std::cout << "  How How " << std::endl;
}