#include <iostream>
#include <algorithm>
#include <iterator>

void printStringMemory(const char *msg);
template<typename T> void printMemory(const T *mem, int n);

int main()
{
    const char *msg = "hello, world";
    int iarray[] = {1, 2, 3, 4};

    std::cout << "---character pointer arithmetic--" << std::endl;
    printStringMemory(msg);
    std::cout << std::endl << std::endl << "---integer pointer arithmetic---" << std:: endl;
    printMemory(iarray, 4);

    // This is why we have iterators
    for(int *p=iarray; p != iarray+4; p++) {
        std::cout << *p << std::endl;
    }

    // high level array sort
    int ar[] = {12, 0, -1, 524};
    std::sort(ar, ar+4);

    // quickly print an array
    std::cout << "{";
    std::copy(ar, ar+3, std::ostream_iterator<int>(std::cout, ", "));
    std::cout << ar[3] << "}" << std::endl;

}

void printStringMemory(const char *msg)
{
    while(*msg) {
        std::cout <<  (void*) msg << "\t" << *msg << std::endl; 
        msg = msg + 1;
    }
}

template<typename T> 
void printMemory(const T *mem, int n)
{
    for(int i=0; i<n; i++) {
        std::cout << (void*) mem << "\t" <<  *mem << std::endl;
        mem = mem + 1;
    }
}