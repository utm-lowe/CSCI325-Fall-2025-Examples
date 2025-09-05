#include <iostream>
#include <vector>
#include <string>

struct Person {
  std::string name; int age;
  Person(std::string n, int a): name(std::move(n)), age(a) {}
};

int main() {
  std::vector<Person> people;
  people.push_back(Person("Ada", 36));        // constructs temp, then move
  people.emplace_back("Grace", 39);           // constructs in-place

  for (const auto& p : people)
    std::cout << p.name << " (" << p.age << ")\n";
}