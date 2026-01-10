#include <iostream>
#include <fstream>


int main(int ac, char **av) {

    if(ac == 4 && av[2][0] != '\0')
    {
        std::string buffer_str;
        std::string new_str = av[3];
        std::string old_str = av[2];

        std::string old_file = av[1];
        std::ifstream myfile(av[1]); // file opned
        // check if file is open && can be read
        if(!(std::getline(myfile, buffer_str, '\0')))
        {
            std::cout << "Error: file is empty or cannot be read" << std::endl;
            return 1;
        }
        std::ofstream new_file((old_file + ".replace").c_str()); // new file created

        size_t i = 0;
        while(i < buffer_str.length())
        {
            size_t pos = buffer_str.find(old_str, i);
            // if not found, break
            if (pos == std::string::npos)
                break;
            buffer_str.erase(pos, old_str.length()); // remove old_str from buffer_str
            buffer_str.insert(pos, new_str); // insert new_str in to buffer_str
            i = pos + new_str.length(); // move index forward
        }
        new_file << buffer_str; // write modified buffer_str to new file
    }
    else
    {
        std::cout << "Error: invalid number of arguments" << std::endl;
        std::cout << "Usage: ./replace <filename> <string_to_replace> <replacement_string>" << std::endl;
        return 1;
    }
    return 0;

}