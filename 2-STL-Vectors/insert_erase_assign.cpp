#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v{1,2,3,4};
  v.insert(v.begin()+2, 99);         // 1 2 99 3 4
  v.erase(v.begin()+3);              // 1 2 99 4
  v.assign(3, 7);                    // 7 7 7

  for (int x: v) cout << x << ' ';   // 7 7 7
  cout << "\n";
}