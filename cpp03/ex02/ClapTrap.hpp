#ifndef ClapTrap_HPP
#define ClapTrap_HPP


#include <string>
#include <iostream>


class ClapTrap
{
    protected:
        std::string name;
        int Hit_Point;
        int Energy_Point;
        int Attack_damage;

    public:
        // canonical form
        ClapTrap();
        ClapTrap(const ClapTrap &obj);
        ClapTrap(const std::string name);
        ClapTrap &operator=(const ClapTrap &obj);
        ~ClapTrap();
        // member functions
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif