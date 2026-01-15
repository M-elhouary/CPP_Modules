#ifndef FragTrap_HPP
#define FragTrap_HPP

#include "ScavTrap.hpp"
#include <string>
#include <iostream>


class FragTrap : public ClapTrap
{
    public:
        // canonical form
        FragTrap();
        FragTrap(const FragTrap &obj);
        FragTrap(const std::string name);
        FragTrap &operator=(const FragTrap &obj);
        ~FragTrap();
        // member functions
        void attack(const std::string &target);
        void highFivesGuys(void);
};

#endif
