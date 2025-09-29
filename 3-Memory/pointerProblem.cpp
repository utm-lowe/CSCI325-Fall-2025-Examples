#include <iostream>

int main()
{
    int *p = nullptr; // Always make invalid pointers point to nullptr
    p = new int;
    *p = 5;
    
    std::cout << *p << std::endl;
    delete p;
    p = nullptr; // after delete always make things nullptr if the pointer is going to live
    
    std::cout << *p << std::endl;
}