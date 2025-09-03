#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> v{5,1,4,2,3};

  sort(v.begin(), v.end());              // ascending
  cout << "asc: "; for (int x: v) cout << x << ' '; cout << "\n";

  sort(v.begin(), v.end(), greater<int>()); // descending
  cout << "desc: "; for (int x: v) cout << x << ' '; cout << "\n";

  // custom: odds first ascending, then evens ascending
  sort(v.begin(), v.end(), [](int a, int b){
    if ((a%2)!=(b%2)) return a%2==1;
    return a < b;
  });
  cout << "odds-first: "; for (int x: v) cout << x << ' '; cout << "\n";
}