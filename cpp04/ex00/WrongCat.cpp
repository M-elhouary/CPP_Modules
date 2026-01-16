#include "WrongCat.hpp"


// Default constructor
WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}


// Copy constructor
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    *this = other;
    std::cout << "WrongCat copy constructor called" << std::endl;
}


// Assignment operator
WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}

// Destructor
WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

// makeSound method
void WrongCat::makeSound() const {
    std::cout << "Wrong Meow!" << std::endl;
}