#include <iostream>
#include <vector>


int main() {
  std::vector<int> v;
  std::cout << "start: size=" << v.size()
       << " cap=" << v.capacity() << "\n";
  for (int i = 1; i <= 16; ++i) {
    v.push_back(i);
    //if (i == 1 || (i & (i - 1)) == 0) { // print at 1,2,4,8,16
      std::cout << "i=" << i
           << " size=" << v.size()
           << " cap=" << v.capacity() << "\n";
    //}
  }
}