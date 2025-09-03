#include <iostream>
#include <vector>
#include <string>


int main() {
  std::vector<int> a;                 // default
  std::vector<int> b(5);              // 5 zeros
  std::vector<int> c(5, 7);           // 5 sevens
  std::vector<int> d{1,2,3,4};        // list-init
  std::vector<std::string> s(5, "chicken");

  std::cout << "a.size=" << a.size() << "\n";

  std::cout << "b: "; 
  
  // This is a C++ foreach loop
  // You can do this with any iterator based container
  for (int x: b) {
    std::cout << x << ' '; 
  }

  /* The above is shorthand for
     for(std::vector<int>::iterator it = b.begin(); it != b.end(); it++) {
       int x = *it;
       std::cout << x << "\n";
     }
  */

  std::cout << "\n";
  
  std::cout << "c: "; for (int x: c) std::cout << x << ' '; std::cout << "\n";
  std::cout << "d: "; for (int x: d) std::cout << x << ' '; std::cout << "\n";
  std::cout << "s: "; for (std::string &x: s) std::cout << x << ' '; std::cout << "\n";
}