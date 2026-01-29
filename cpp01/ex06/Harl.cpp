

#include "Harl.hpp"


Harl::Harl()
{}


void  Harl::debug(){
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;

}


void Harl::info(){
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;

}

void Harl::warning(){
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;

}




/*
** complain uses a switch statement to implement the filter.
** It finds the index of the level, then falls through from that case
** to execute all more severe levels.
** Note: The implementation here manually calls subsequent functions instead of standard switch fallthrough syntax for function calls, 
** but achieves the same result (executing 0->3, 1->3, etc).
*/
void Harl::complain(std::string level)
{
    int index = -1; // Default to -1 (not found)
    void (Harl::*function[]) (void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };

    std::string ar_level[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (size_t i = 0; i < 4; i++)
    {
        if(ar_level[i] == level){
           index = i;
           break;
        }
    }
    
    switch (index)
    {
    case 0:
        ( this->*function[0])();
        // Fallthrough
    case 1:
        ( this->*function[1])();    
        // Fallthrough
    case 2:
        ( this->*function[2])();    
        // Fallthrough
    case 3:
        ( this->*function[3])();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}    

