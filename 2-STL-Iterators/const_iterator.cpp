#include <iostream>
#include <vector>

int main() {
  const std::vector<int> v{10,20,30};

  for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
    std::cout << *it << " ";
  std::cout << "\n";
}