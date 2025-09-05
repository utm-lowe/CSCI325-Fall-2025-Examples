#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> v{5,1,4,2,3};

  auto it = find(v.begin(), v.end(), 4);
  if (it != v.end())
    std::cout << "Found 4 at index " << (it - v.begin()) << "\n";

  sort(v.begin(), v.end());
  std::cout << "Sorted: ";
  for (auto x : v) std::cout << x << " ";
  std::cout << "\n";
}