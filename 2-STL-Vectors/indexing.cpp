#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v{10,20,30};
  cout << "v[1]=" << v[1] << "\n";        // OK

  try {
    cout << "v.at(5)=" << v.at(5) << "\n"; // throws
  } catch (const out_of_range& e) {
    cout << "Exception: " << e.what() << "\n";
  }
}