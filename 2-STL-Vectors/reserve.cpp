#include <iostream>
#include <vector>

int main() {
  std::vector<int> a, b;
  b.reserve(16);                 // pre-allocate

  for (int i = 0; i < 16; ++i) {
    a.push_back(i);
    b.push_back(i);
    if (i == 0 || i == 3 || i == 7 || i == 15) {
      std::cout << "i=" << i
           << "  a.cap=" << a.capacity()
           << "  b.cap=" << b.capacity() << "\n";
    }
  }
}