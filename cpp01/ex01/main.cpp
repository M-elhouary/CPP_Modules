#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name);

int main()
{
    int N = 6;
    Zombie* Horde = zombieHorde(N, "Zombie_Horde");
    for(int i = 0; i < N; i++)
    {
        Horde[i].announce();
    }
    delete[] Horde;
    return 0;
}