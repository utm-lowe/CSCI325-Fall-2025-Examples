/**
 * @file test.cpp
 * @author Bob Lowe <rlowe8@utm.edu>
 * @brief A little test program to time various vector and list operations
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "timingFixture.hpp"
#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <random>
#include <ctime>

// A few global variables (It's ok. Trust me, I have a PhD)
unsigned int n;
std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));

// function prototypes
template<typename T> void randomPushBack(T& container);
template<typename T> void randomInsert(T& container);


int main(int argc, char **argv)
{
    if(argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
    }
    n = std::strtoi(argv[1]);

    std::vector<int>  v;
    std::list<int> l;
    
    return 0;
}




template<typename T> 
void randomPushBack(T& container)
{
    std::uniform_int_distribution<int> dist(0, n*10);
    for(int i=0; i<10; i++) {
        container.push_back(dist(mt));
    }
}


template<typename T> void randomInsert(T& container)
{
    std::uniform_int_distribution<int> dist(0, n*10);
    std::uniform_int_distribution<int> index(0, n-2);
    for(int i=0; i<10; i++) {
        container.insert(container.begin() + index(mt), dist(index));
    }
}
