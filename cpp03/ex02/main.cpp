#include "FragTrap.hpp"

int main()
{
    std::cout << "=== FragTrap Test ===" << std::endl
              << std::endl;

    // Test 1: Constructor
    std::cout << "Test 1: Creating two FragTraps" << std::endl;
    FragTrap A("Alice");
    FragTrap B("Bob");
    std::cout << std::endl;

    // Test 2: Attack functionality
    std::cout << "Test 2: Alice attacks Bob" << std::endl;
    A.attack("Bob");
    std::cout << std::endl;

    // Test 3: Take damage
    std::cout << "Test 3: Bob takes 20 damage" << std::endl;
    B.takeDamage(20);
    std::cout << std::endl;

    // Test 4: Multiple attacks to deplete energy
    std::cout << "Test 4: Alice attacks Bob multiple times" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        A.attack("Bob");
    }
    std::cout << std::endl;

    // Test 5: Repair functionality
    std::cout << "Test 5: Bob repairs himself" << std::endl;
    B.beRepaired(15);
    std::cout << std::endl;

    // Test 6: FragTrap special ability
    std::cout << "Test 6: Alice requests high fives" << std::endl;
    A.highFivesGuys();
    std::cout << std::endl;

    // Test 7: Massive damage
    std::cout << "Test 7: Bob takes 95 damage" << std::endl;
    B.takeDamage(95);
    std::cout << std::endl;

    // Test 8: Copy constructor test
    std::cout << "Test 8: Creating copy of Alice" << std::endl;
    FragTrap C(A);
    std::cout << std::endl;

    std::cout << "=== End of Test ===" << std::endl;
    return 0;
}