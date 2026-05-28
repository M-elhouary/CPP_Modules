#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data originalData;
    originalData.s1 = "Hello";
    originalData.n = 42;
    originalData.s2 = "World";

    uintptr_t serializedPtr = Serializer::serialize(&originalData);
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    std::cout << "Original pointer:   " << &originalData << std::endl;
    std::cout << "Serialized:         " << serializedPtr << std::endl;
    std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;

    if (deserializedPtr == &originalData)
    {
        std::cout << "\nSerialization and deserialization successful!" << std::endl;
        std::cout << "Data content:" << std::endl;
        std::cout << "s1: " << deserializedPtr->s1 << std::endl;
        std::cout << "n:  " << deserializedPtr->n << std::endl;
        std::cout << "s2: " << deserializedPtr->s2 << std::endl;
    }
    else
    {
        std::cout << "\nSerialization and deserialization failed!" << std::endl;
    }

    return 0;
}
