
#ifndef CLAPTRAP_HPP

#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{

private:
	std::string name;
	int Hit_Point;
	int Energy_Point;	
	int Attack_damage;

public:
	ClapTrap();
	ClapTrap(const ClapTrap &obj);
	ClapTrap(const std::string name);
	ClapTrap &operator=(const ClapTrap &obj);


	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	~ClapTrap();
};

#endif