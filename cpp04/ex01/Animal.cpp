#include "Animal.hpp"

// Default constructor
Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &other)
{
    this->type = other.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

// Assignment operator
Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

// Destructor
Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

// Getter for type
std::string Animal::getType() const
{
    return this->type;
}

// Setter for type
std::string Animal::setType(std::string &type)
{
    this->type = type;
    return this->type;
}

// makeSound method
void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}
