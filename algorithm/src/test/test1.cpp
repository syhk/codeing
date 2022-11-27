#include "algorithm"
#include "iostream"
#include "vector"

using namespace std;

template <typename T>
auto print_type_info(const T& t) {
  if constexpr (std::is_integral<T>::value) {
    return t + 1;
  } else {
    return t + 0.001;
  }
}

template <typename T, typename... Ts>
auto printf3(T value, Ts... args) {
  cout << value << endl;
  (void)std::initializer_list<T>{
      ([&args] { cout << args << endl; }(), value)...};
}

int main() {
  cout << print_type_info(5) << endl;
  cout << print_type_info(3.14) << endl;
  printf3("syhk", "syhk2", "syhk3", "syhk4", "syhk5");

  return 0;
}