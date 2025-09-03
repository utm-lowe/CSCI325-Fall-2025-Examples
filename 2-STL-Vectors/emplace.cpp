#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Person {
  string name; int age;
  Person(string n, int a): name(move(n)), age(a) {}
};

int main() {
  vector<Person> people;
  people.push_back(Person("Ada", 36));        // constructs temp, then move
  people.emplace_back("Grace", 39);           // constructs in-place

  for (const auto& p : people)
    cout << p.name << " (" << p.age << ")\n";
}