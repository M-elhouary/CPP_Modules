#include "Contact.hpp"

/*
  Sets the value of a specific field in the contact based on the flag.
  flag: The field to update (FIRSTN, LASTEN, etc.)
  value: The string value to set.
*/
void Contact::SetValue(t_flag flag, std::string value)
{
    if(flag == FIRSTN)
        this->firstName = value;
    else if(flag == LASTEN)
        this->lasteName = value;
    else if (flag == PHONE)
        this->phoneNumber = value;
    else if (flag == SECRET)
        this->darkestSecret = value;
    else if(flag == NICKN)
        this->nickName = value;

}

std::string Modified_value(std::string  str_value)
{
    if(str_value.length() > 10)
        return (str_value.substr(0, 9) + ".");
    return str_value;
}

/*
    Displays the contact information.
    flag: If 0, displays a summary (formatted columns).
      If non-zero, displays full details of the contact.
*/
void Contact::DesplayValue(int flag)
{
    if(flag == 0)
    {
     std::cout << std::setw(10) << Modified_value(firstName) << "|" ;
     std::cout << std::setw(10) << Modified_value(lasteName) << "|" ;
     std::cout << std::setw(10) << Modified_value(nickName) << "|"  << std::endl;
    }
    else
    {
        std::cout << firstName << std::endl;
        std::cout << lasteName << std::endl;
        std::cout << nickName << std::endl;
        std::cout << phoneNumber << std::endl;
        std::cout << darkestSecret << std::endl;
    }
}