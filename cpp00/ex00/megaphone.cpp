//============subject=============================
// convert each arg from lowercase to uppercase  =
//================================================



//==================wath shoulde know================
/*
         Namespaces
         Stdio streams
         Class and instance
         Member attributes and member function
         This
         Initialization list
         Const
         Visibility
         Class vs struct
         Accessors
         Comparisons
         Non member attributes and non member functions
         Pointers to members
*/
//================================================


#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if(ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<  std::endl;
    int i;
    int j;
    char ch;
    i = 1;
    while (av[i])
    {
        j = 0;
        while(av[i][j])
        {
            if(tolower(av[i][j]))
            {
                ch = toupper(av[i][j]);
                j++;
            }
            else
            {
                ch = av[i][j] ;
                j++; 
            }
            std::cout << ch;
        }
        std::cout << " " ;
        i++;
    }
    std::cout << std::endl;
    return (0);
}