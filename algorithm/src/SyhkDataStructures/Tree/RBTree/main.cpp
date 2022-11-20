#include "./RBTree.h"
#include "vector"
using namespace std;

int main() {
  vector<int> vec = {55, 87, 56, 74, 96, 22, 62, 20, 70, 68, 90, 50};
  RBTree rb;
  for (auto i : vec) {
    rb.add(i);
  }
  rb.ProT(rb.getParent());
  return 0;
}