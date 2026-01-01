#include "PhoneBook.hpp"





// class
// object
// instance
// member attributes
// member function
// this
// initialization list
// namespaces
// std
// 

int main()
{
  PhoneBook ContactBook;
  std::string string_input;
  try
  {
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
  }
  catch(const std::exception& e)
  {
    std::cout << "\nProgram terminated." << std::endl;
  }
  return (0);
}