#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> a;                 // default
  vector<int> b(5);              // 5 zeros
  vector<int> c(5, 7);           // 5 sevens
  vector<int> d{1,2,3,4};        // list-init

  cout << "a.size=" << a.size() << "\n";
  cout << "b: "; for (int x: b) cout << x << ' '; cout << "\n";
  cout << "c: "; for (int x: c) cout << x << ' '; cout << "\n";
  cout << "d: "; for (int x: d) cout << x << ' '; cout << "\n";
}