#ifndef __PERSON__HEAD__
#define __PERSON__HEAD__
#include <string>
using std::string;
class Person {
 public:
  Person() = default;
  Person(int age, string name) : age(age), name(name){};

 private:
  int age;
  string name;
};

#endif  // __PERSON__HEAD__