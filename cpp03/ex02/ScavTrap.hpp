#ifndef ScavTrap_HPP
#define ScavTrap_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

// ScavTrap class definition inheriting from ClapTrap
class ScavTrap : public ClapTrap
{
    public:
        // canonical form
        ScavTrap();
        ScavTrap(const ScavTrap &obj);
        ScavTrap(const std::string name);
        ScavTrap &operator=(const ScavTrap &obj);
        ~ScavTrap();
        // member functions
        void attack(const std::string &target);
        void guardGate();
};

#endif 


