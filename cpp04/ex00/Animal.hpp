#ifndef Animal_HPP
#define Animal_HPP


#include <iostream>
#include <string>

class Animal {

    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();
        std::string getType() const;
        std::string setType(std::string &type);
        virtual void makeSound() const;
};

#endif 
