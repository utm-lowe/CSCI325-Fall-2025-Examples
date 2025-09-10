/**
 * @file memdisp.cpp
 * @author Robert Lowe <rlowe8@utm.edu>
 * @brief Visualize memory in an attempt to grok pointers.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>

/**
 * @brief A handy way to store some details about variables.
 * 
 */
struct VarSpec
{
    std::string name;
    const void *ptr;
    std::size_t size;

    /**
     * @brief Compare by memory location.
     * 
     * @param other 
     * @return true 
     * @return false 
     */
    bool operator<(const VarSpec &other) const
    {
        return ptr < other.ptr;
    }
};

/**
 * @brief Display memory for a variable
 * 
 * @param varname Name to print (can be blank)
 * @param ptr The address to begin the display
 * @param size How much memory to display
 */
void dispvar(const std::string &varname, const void *ptr, std::size_t size);

/**
 * @brief Draw some pretty boxes and line type things.
 * 
 */
void dispsep();

/**
 * @brief Display the variables in the vars list complete with gaps.
 * 
 * @param vars 
 */
void dispmem(std::vector<VarSpec> vars);


int main()
{
    
}

// Display memory for a variable
void dispvar(const std::string &varname, const void *ptr, std::size_t size)
{
    const unsigned char *p;
    const unsigned char *endptr = static_cast<const unsigned char *>(ptr) + size;
    int line = 0;

    // display each variable
    for (p = static_cast<const unsigned char *>(ptr); p < endptr; ++p, ++line)
    {
        // print a nicely formatted memory cell
        std::cout << std::hex << std::setfill('0')
                  << "0x" << std::setw(16) << (unsigned long long)p
                  << std::setfill(' ')
                  << " | 0x"
                  << std::setfill('0')
                  << std::setw(2) << (unsigned int)(*p)
                  << " |";
       
        // If it's the first line, print the variable label.
        if (p == ptr)
        {
            std::cout << std::setfill(' ') << ' ' << std::setw(20) << std::left << varname << "|" << std::right;
        }
        else
        {
            std::cout << std::setfill(' ') << std::setw(22) << "|";
        }
        std::cout << std::endl;
    }
}

// Draw some pretty boxes and line type things.
void dispsep()
{
    std::cout << std::setfill(' ')
              << std::setw(19) << ""
              << "+------+"
              << std::setfill('-') << std::setw(21) << ""
              << "+"
              << std::setfill(' ') << std::endl;
}

// Display the variables in the vars list complete with gaps.
void dispmem(std::vector<VarSpec> vars)
{
    VarSpec last = {"", nullptr, 0};        // The last displayed variable

    // sort by memory location
    std::sort(vars.begin(), vars.end());   
    

    for (const auto &var : vars)
    {
        dispsep();

        //handle gaps in the chain
        unsigned char *p1 = static_cast<unsigned char *>(const_cast<void *>(last.ptr));
        unsigned char *p2 = static_cast<unsigned char *>(const_cast<void *>(var.ptr));
        if (p1 != nullptr && p2 > p1 + last.size)
        {
            dispvar("", p1 + last.size, p2 - p1);
            dispsep();
        }
        dispvar(var.name, var.ptr, var.size);
        last = var;
    }
    dispsep();
}
