#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
    this->current_index = 0;
    this->total_index = 0;
}

void PhoneBook::Desplay_by_Index()
{
    std::cout << "Enter Index: " ;
    std::string index_value_str;
    int Index;
    std::getline(std::cin, index_value_str);
    std::stringstream ss(index_value_str);
    if(!(ss >> Index) || Index < 0 || !ss.eof() || Index > current_index - 1)
    {
        std::cout << "Invalid index. Please enter a valid number." << std::endl;
        return;
    }
    contacts[Index].DesplayValue(1);

}

std::string parse(std::string str)
{
    
    std::string input_value;
    while (true)
    {
        std::cout << str;
        if(!std::getline(std::cin, input_value))
        {
            std::cout << "\nEOF detected (Ctrl+D) Exiting ADD command " << std::endl;
            throw std::runtime_error("EOF");
        }
        if (input_value.empty())
        {
            std::cout << "Input cannot be empty. Please try again." << std::endl;
            continue;
        }
        return input_value;
    }
}




void PhoneBook::Add_New_Contact()
{
    if(current_index == 8)
    {
        current_index = 0;
        total_index = 1;
    }
    contacts[current_index].SetValue(FIRSTN, parse("Enter First Name: "));
    contacts[current_index].SetValue(LASTEN, parse("Enter last Name: "));
    contacts[current_index].SetValue(PHONE, parse("Enter Phone Number: "));
    contacts[current_index].SetValue(NICKN, parse("Enter Nick Name: "));
    contacts[current_index].SetValue(SECRET, parse("Enter DarkSecret: "));
    current_index++;
}

void PhoneBook::Search_A_Contact()
{
    int i = 0;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << "Index" ;
    std::cout << "|" << std::setw(10) << "First Name";
    std::cout << "|" << std::setw(10) << "Last  Name";
    std::cout << "|" << std::setw(11) << "Nick Name|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    while (i < current_index || (total_index == 1 && i < 8) ) 
    {
        std::cout << "|" << std::setw(10) << i << "|";
        contacts[i].DesplayValue(0);
        i++;
    }
    std::cout << "---------------------------------------------" << std::endl;
    Desplay_by_Index();
}


