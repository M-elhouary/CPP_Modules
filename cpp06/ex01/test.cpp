#include <iostream>

int main()
{
    // Let's use a number that will occupy more than one byte to make it interesting.
    // 65793 in hex is 0x00010101.
    int* a = new int(65793);

    std::cout << "The integer 'a' has the value: " << *a << std::endl;
    std::cout << "It is stored in " << sizeof(int) << " bytes." << std::endl;
    std::cout << "Here is the value of each of those 4 bytes in memory:" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;

    // We cast the address of 'a' to a char pointer.
    // Since a char is 1 byte, this lets us move through memory one byte at a time.
    char *byte_pointer = reinterpret_cast<char*>(a);

    for (size_t i = 0; i < sizeof(int); ++i)
    {
        // We print the value of the byte at the current position.
        // We cast the char to an int to see its numeric value instead of an ASCII character.
        std::cout << "Byte " << i << ": " << static_cast<int>(byte_pointer[i]) << std::endl;
    }
    std::cout << *byte_pointer << std::endl;
    std::cout << byte_pointer << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Note: The order of bytes (endianness) depends on your system's architecture." << std::endl;

    return 0;
}
