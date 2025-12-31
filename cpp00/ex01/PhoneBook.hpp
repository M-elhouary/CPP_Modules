#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <sstream>

/*
  The PhoneBook class manages a collection of up to 8 contacts.
  It handles adding new contacts (overwriting the oldest if full)
  and searching for existing contacts.
*/
class PhoneBook
{
    private:
        Contact contacts[8];
        int current_index;
        int total_index;
    public:
    PhoneBook();
    void Add_New_Contact();
    void Search_A_Contact();
    void Desplay_by_Index();
};

#endif