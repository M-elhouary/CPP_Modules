#include "Zombie.hpp"

Zombie::Zombie(void) : name() {} // Default constructor for array allocation

Zombie::~Zombie() {
    std::cout << this->name << " is destroyed" << std::endl; // Destructor for cleanup message
}

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl; // Announce method
}

void Zombie::setName(std::string name) { // Setter for name
    this->name = name;
}