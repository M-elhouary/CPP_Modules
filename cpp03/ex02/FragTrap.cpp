#include "FragTrap.hpp"

// inherited Constructor implementations
FragTrap::FragTrap() : ClapTrap()
{
    this->Hit_Point = 100;
    this->Energy_Point = 100;
    this->Attack_damage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

// Parameterized constructor inheriting from ClapTrap
FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    this->Hit_Point = 100;
    this->Energy_Point = 100;
    this->Attack_damage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

// Copy constructor inheriting from ClapTrap
FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

// Copy assignment operator inheriting from ClapTrap
FragTrap &FragTrap::operator=(const FragTrap &obj)
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->name = obj.name;
        this->Hit_Point = obj.Hit_Point;
        this->Energy_Point = obj.Energy_Point;
        this->Attack_damage = obj.Attack_damage;
    }
    return *this;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    // check if FragTrap has enough energy and is alive
    if (this->Energy_Point > 0 && this->Hit_Point > 0)
    {
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing "
                  << this->Attack_damage << " points of damage!" << std::endl;
        this->Energy_Point--;
    }
    else
        std::cout << "sir trini";
}

void FragTrap::highFivesGuys()
{
    // check if FragTrap is alive
    if (this->Hit_Point > 0)
        std::cout << "FragTrap named: " << name << " requests high-fives!" << std::endl;
    else
        std::cout << "FragTrap named: " << name << " has been destroyed!" << std::endl;
}
