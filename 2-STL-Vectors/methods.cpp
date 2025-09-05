#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  std::cout << "front=" << v.front() << " back=" << v.back() << "\n";

  v.pop_back();                  // remove 3
  std::cout << "size=" << v.size() << "\n";

  v.resize(5, 9);                // grow with fill value
  std::cout << "after resize: ";
  for (int x: v) std::cout << x << ' '; std::cout << "\n";

  v.clear();
  std::cout << "cleared size=" << v.size() << "\n";
}