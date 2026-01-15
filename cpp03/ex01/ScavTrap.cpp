#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
    // this->Hit_Point = 100;
    // this->Energy_Point = 50;
    // this->Attack_damage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    // this->Hit_Point = 100;
    // this->Energy_Point = 50;
    // this->Attack_damage = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->name = obj.name;
        this->Hit_Point = obj.Hit_Point;
        this->Energy_Point = obj.Energy_Point;
        this->Attack_damage = obj.Attack_damage;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}


void ScavTrap::attack(const std::string &target)
{
    if (this->Energy_Point > 0 && this->Hit_Point > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing "
                  << this->Attack_damage << " points of damage!" << std::endl;
        this->Energy_Point--;
    }
    else
        std::cout << "sir trini";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}



