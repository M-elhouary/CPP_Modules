#include "Fixed.hpp"


const int Fixed::frac = 8; // Number of fractional bits


// Default constructor implementation
Fixed::Fixed() : number(0) {
    std::cout << "Default constructor called" << std::endl; 
}


// Copy constructor implementation
Fixed::Fixed(const Fixed &obj) { 
    std::cout << "Copy constructor called" << std::endl;
    this->number = obj.number;
}


// Copy assignment operator implementation 
Fixed &Fixed::operator=(const Fixed &obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj) {
        this->number = obj.number;
    }
    return *this;
}
// Getter for the raw fixed-point value
int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->number;
}
// Setter for the raw fixed-point value
void Fixed::setRawBits(int const raw) {
    this->number = raw;
}


// Destructor implementation
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
