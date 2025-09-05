#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{10,20,30,40,50};

  auto it1 = v.begin();
  auto it2 = v.begin() + 3; // points to 40

  std::cout << "*it1 = " << *it1 << "\n";
  std::cout << "*it2 = " << *it2 << "\n";
  std::cout << "Distance it2 - it1 = " << (it2 - it1) << "\n";
  std::cout << "*(it2 - 2) = " << *(it2 - 2) << "\n";

  if (it1 < it2) std::cout << "it1 comes before it2\n";
}