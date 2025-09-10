#include <iostream>

int main()
{
    int x=26984;
    char *s = (char*) &x;

    std::cout << s << std::endl;
}