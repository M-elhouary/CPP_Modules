#include "Cat.hpp"

// Default constructor

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

// Assignment operator
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

// Destructor
Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}
// makeSound method
void Cat::makeSound() const
{
    std::cout << " Meow Meow" << std::endl;
}
