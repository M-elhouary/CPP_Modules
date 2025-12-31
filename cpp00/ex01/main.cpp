#include "PhoneBook.hpp"

/*
  Main function: Entry point of the PhoneBook application.
  Runs a loop that accepts commands (ADD, SEARCH, EXIT) from the user.
  - ADD: Adds a new contact.
  - SEARCH: Lists contacts and allows viewing details.
  - EXIT: Terminates the program.
*/
int main()
{
  // 
  PhoneBook ContactBook;
  std::string string_input;
  while (true)
  {
    std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
      if(!(std::getline(std::cin, string_input)))
        break;
    if (string_input == "ADD")
                ContactBook.Add_New_Contact();
    else if(string_input == "SEARCH")
        ContactBook.Search_A_Contact();
    else if(string_input == "EXIT")
        break;
  }
  return (0);
}