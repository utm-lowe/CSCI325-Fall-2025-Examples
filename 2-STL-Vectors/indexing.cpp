#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{10,20,30};
  std::cout << "v[1]=" << v[1] << "\n";        // OK

  try {
    std::cout << "v.at(5)=" << v.at(5) << "\n"; // throws
  } catch (const std::out_of_range& e) {
    std::cout << "Exception: " << e.what() << "\n";
  }
}