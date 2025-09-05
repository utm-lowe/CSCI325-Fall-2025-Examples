#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1,2,3,4};

  std::cout << "Reverse iteration: ";
  for (auto it = v.rbegin(); it != v.rend(); ++it)
    std::cout << *it << " ";
  std::cout << "\n";
}