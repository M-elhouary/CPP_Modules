#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{

public:
    Fixed(); // Default constructor
    Fixed(const Fixed &obj); // Copy constructor 
    Fixed &operator=(const Fixed &obj); // Copy assignment operator
    int getRawBits() const; // Getter for the raw fixed-point value
    void setRawBits(int const raw); // Setter for the raw fixed-point value  && not used in this exercise
    ~Fixed();

private:
    int number;
    static const int frac; // Number of fractional bits not used in this exercise
};

#endif // FIXED_HPP