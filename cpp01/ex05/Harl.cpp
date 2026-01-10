
#include "Harl.hpp"


Harl::Harl() {}


void Harl::complain(std::string level)
{

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
           ( this->*function[i])();
            return;
        }
    }
    

}


void  Harl::debug(){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger";
    std::cout << "I really do!" << std::endl;
}



void Harl::info(){
    std::cout << "I cannot believe adding extra bacon costs more money.";
    std::cout << "You didn't put enough bacon in my burger! If you did";
    std::cout << "I wouldn't be asking for more!" << std::endl;
    
}

void Harl::warning(){
    std::cout << "I think I deserve to have some extra bacon for free.";
    std::cout << "I've been coming for years,";
    std::cout << "whereas you started working here just last month" << std::endl;
    
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;

}