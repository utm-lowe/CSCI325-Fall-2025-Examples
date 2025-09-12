#include <iostream>
#include <algorithm>
#include <iterator>
#include "dynamicArray.hpp"

int main()
{
    csci325::DynamicArray<int> ar{10,2,35,14,-15};

    //sort the list and then print it
    std::sort(ar.begin(), ar.end());
    std::ostream_iterator<int> oit(std::cout, ", ");
    std::cout << '{';
    std::copy(ar.begin(), ar.end()-1, oit);
    std::cout << ar.back() << '}' << std::endl;
}