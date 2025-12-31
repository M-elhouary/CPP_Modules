#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>



typedef enum s_flag {FIRSTN, LASTEN, PHONE, SECRET, NICKN} t_flag;

/*
   The Contact class represents a single contact in the phonebook.
   It stores personal information like first name, last name, phone number, etc.
   It provides methods to set these values and display them.
*/
class Contact {
    private:
        std::string firstName;
        std::string lasteName;
        std::string phoneNumber;
        std::string darkestSecret;
        std::string nickName;
    public:
        void SetValue(t_flag flag, std::string value);
        void  DesplayValue(int flag);
};

#endif



