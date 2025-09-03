#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  cout << "front=" << v.front() << " back=" << v.back() << "\n";

  v.pop_back();                  // remove 3
  cout << "size=" << v.size() << "\n";

  v.resize(5, 9);                // grow with fill value
  cout << "after resize: ";
  for (int x: v) cout << x << ' '; cout << "\n";

  v.clear();
  cout << "cleared size=" << v.size() << "\n";
}