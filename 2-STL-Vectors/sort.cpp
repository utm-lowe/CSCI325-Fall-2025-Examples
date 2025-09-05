#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> v{5,1,4,2,3};

  std::sort(v.begin(), v.end());              // ascending
  std::cout << "asc: "; for (int x: v) std::cout << x << ' '; std::cout << "\n";

  std::sort(v.begin(), v.end(), std::greater<int>()); // descending
  std::cout << "desc: "; for (int x: v) std::cout << x << ' '; std::cout << "\n";

  // custom: odds first ascending, then evens ascending
  std::sort(v.begin(), v.end(), [](int a, int b){
    if ((a%2)!=(b%2)) return a%2==1;
    return a < b;
  });
  std::cout << "odds-first: "; for (int x: v) std::cout << x << ' '; std::cout << "\n";
}