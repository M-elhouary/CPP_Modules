#include "ClapTrap.hpp"




int main()
{

    ClapTrap A("youyo");
    ClapTrap B("bobo");

    A.attack("bobo");
    B.takeDamage(10);

    B.beRepaired(5);
    B.takeDamage(5);

    return 0;
}