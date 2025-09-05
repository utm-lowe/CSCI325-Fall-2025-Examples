#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{100,200,300};
  auto it = v.begin();

  std::cout << *it << "\n";    // dereference
  ++it;                   // increment
  std::cout << *it << "\n";
  it += 1;                // advance by offset
  std::cout << *it << "\n";
}