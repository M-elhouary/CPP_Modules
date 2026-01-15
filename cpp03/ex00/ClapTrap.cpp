#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), Hit_Point(10), Energy_Point(10), Attack_damage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), Hit_Point(10), Energy_Point(10), Attack_damage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    this->name = obj.name;
    this->Hit_Point = obj.Hit_Point;
    this->Energy_Point = obj.Energy_Point;
    this->Attack_damage = obj.Attack_damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->name = obj.name;
        this->Hit_Point = obj.Hit_Point;
        this->Energy_Point = obj.Energy_Point;
        this->Attack_damage = obj.Attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->Energy_Point > 0 && this->Hit_Point > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "
                  << this->Attack_damage << " points of damage!" << std::endl;
        this->Energy_Point--;
    }
    else
        std::cout << "sir trini";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit_Point > 0)
    {
        Hit_Point -= amount;
        if (Hit_Point < 0)
            Hit_Point = 0;
        std::cout << "ClapTrap " << name << " takes " << amount
                  << " points of damage! Remaining hit points: " << Hit_Point << std::endl;
    }
    else
        std::cout << "wac wacwac fatima Mohamed losy mat wac wacwac" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->Energy_Point > 0 && this->Hit_Point > 0)
    {
        this->Energy_Point--;
        this->Hit_Point += amount;
        std::cout << "ClapTrap " << name << " is repaired by "
                  << amount << " points! Current hit points: " << this->Hit_Point << std::endl;
    }
    else
        std::cout << "ClapTrap " << name << " has insufficient energy or hit points to repair" << std::endl;
}
