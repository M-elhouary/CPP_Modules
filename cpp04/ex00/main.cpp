#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "========== Animal Demo ==========" << std::endl;

    const Animal *base = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << "\n--- Types ---" << std::endl;
    std::cout << "Dog pointer type:   " << dog->getType() << std::endl;
    std::cout << "Cat pointer type:   " << cat->getType() << std::endl;
    std::cout << "Animal pointer type:" << base->getType() << std::endl;

    std::cout << "\n--- Sounds (virtual) ---" << std::endl;
    std::cout << "Dog says:    ";
    dog->makeSound();
    std::cout << "Cat says:    ";
    cat->makeSound();
    std::cout << "Animal says: ";
    base->makeSound();

    std::cout << "\n--- Cleanup ---" << std::endl;
    delete base;
    delete dog;
    delete cat;

    std::cout << "\n====== WrongAnimal Demo ======" << std::endl;
    WrongAnimal wrongBase;
    WrongCat wrongDerived;
    WrongAnimal *wrongPoly = &wrongDerived;

    std::cout << "\n--- Types ---" << std::endl;
    std::cout << "WrongAnimal type:     " << wrongBase.getType() << std::endl;
    std::cout << "WrongCat type:        " << wrongDerived.getType() << std::endl;
    std::cout << "WrongAnimal* to Cat:  " << wrongPoly->getType() << std::endl;

    std::cout << "\n--- Sounds (no virtual) ---" << std::endl;
    std::cout << "WrongAnimal says: ";
    wrongBase.makeSound();
    std::cout << "WrongCat says:    ";
    wrongDerived.makeSound();
    std::cout << "Base ptr to Cat:  ";
    wrongPoly->makeSound();

    std::cout << "===============================" << std::endl;
    return 0;
}
