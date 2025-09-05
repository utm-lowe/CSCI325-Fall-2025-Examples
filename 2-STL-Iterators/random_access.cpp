#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{10,20,30,40};

  auto it = v.begin();
  std::cout << "it[2] = " << it[2] << "\n";  // random access
  std::cout << "*(it+3) = " << *(it+3) << "\n";
}