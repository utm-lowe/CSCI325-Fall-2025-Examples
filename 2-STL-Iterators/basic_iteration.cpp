#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1,2,3,4};

  std::cout << "Forward iteration: ";
  for (auto it = v.begin(); it != v.end(); ++it)
    std::cout << *it << " ";
  std::cout << "\n";
}