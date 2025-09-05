#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>


int main() {
  std::cout << "Enter 3 numbers: ";
  std::istream_iterator<int> in(std::cin), end;
  std::vector<int> v(in, end);

  std::cout << "You entered: ";
  std::ostream_iterator<int> out(std::cout, " ");
  copy(v.begin(), v.end(), out);
  std::cout << "\n";
}