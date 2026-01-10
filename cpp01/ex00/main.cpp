#include    "Zombie.hpp"

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

int main() {

    randomChump("Stack_Zombie");
    Zombie* heapZombie = newZombie("Heap_Zombie");
    heapZombie->announce();
    delete heapZombie;

    return 0;
}