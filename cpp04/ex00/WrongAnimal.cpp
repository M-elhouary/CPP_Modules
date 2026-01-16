
#include "WrongAnimal.hpp"



// Default constructor initializing type to "WrongAnimal" by default
WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructor called" << std::endl;
}


// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    *this = other;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

// Assignment operator
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}


// Destructor
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}


// makeSound method
void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal generic sound!" << std::endl;
}

// Getter for type
std::string WrongAnimal::getType() const {
    return this->type;
}       