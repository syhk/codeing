#include "iostream"
#include "set"
using namespace std;

int main() {
  set<int*> s;
  int* a = new int(4);
  int* b = new int(4);

  cout << boolalpha;
  bool flag = (s.insert(a)).second;
  flag = (s.insert(b)).second;
  flag = (s.insert(a)).second;
  cout << flag << endl;
  return 0;
}