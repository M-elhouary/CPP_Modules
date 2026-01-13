#ifndef FIXED_HPP
#define FIXED_HPP   
#include <iostream>
#include <cmath>    
class Fixed
{   

public:
    Fixed(); // Default constructor
    Fixed(const Fixed &obj); // Copy constructor
    Fixed(int value); // Int constructor
    Fixed(float value); // Float constructor
    Fixed &operator=(const Fixed &obj); // Copy assignment operator
    int toInt() const; // Convert to int
    float toFloat() const; // Convert to float
    int getRawBits() const;// Getter for the raw fixed-point value
    void setRawBits(int const raw);// Setter for the raw fixed-point value
    ~Fixed();// Destructor
private:
    int number; // Fixed-point number representation
    static const int frac; // Number of fractional bits
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj); // Overload of the insertion operator

#endif // FIXED_HPP