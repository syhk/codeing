#include <initializer_list>
#include <iterator>
#include <utility>

#include "iostream"
#include "stdio.h"
#include "twoarrayfind.h"
#include "vector"

void func();
int climbStairs(int n);

int main() {
  // syhk x;
  // int arr[16] = {1, 2,  8,  9, 2, 4,  9, 12, 4,
  //                7, 10, 13, 6, 8, 11, 15
  // };  // 行列
  // cout << x.test1(arr, 4, 4, 7);
  // func();
  std::cout << climbStairs(45);
}
template <class T>
struct S {
  std::vector<T> v;
  S(std::initializer_list<T> l) : v(l) {
    std::cout << "constructed with a " << l.size() << "-element list \n";
  }
  void append(std::insert_iterator<T> l) {
    v.insert(v.end(), l.begin(), l.end());
  }
  std::pair<const T*, std::size_t> c_arr() const { return {&v[0], v.size()}; }
};
template <typename T>
void templated_fn(T) {}
void func() {
  S<int> s = {1, 2, 3, 4, 5};
  for (auto i : s.v) {
    std::cout << i << '\t';
  }
}
class Base {
 public:
  virtual void func1() final{};
  virtual void func2(){};
  void func3();
};
class Derived : public Base {
  void func2() override {}
};
int climbStairs(int n) {
  if (n == 1) return 1;
  if (n == 2) return 2;
  if (n == 3) return 3;
  if (n <= 0) return 0;
  return climbStairs(n - 1) + climbStairs(n - 2);
}
