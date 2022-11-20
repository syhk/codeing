#include "AVLtree.h"
#include "iostream"
#include "vector"

using std::cout;
using std::endl;
using std::vector;

int main(void) {
  vector<int> vec = {7, 4, 9, 2, 5, 8, 11, 3, 12, 1};
  AVLNode *root = nullptr;
  for (int i : vec) {
    std::cout << i << endl;
    root = insert(root, vec[i]);
  }
  inOrder(root);

  root = deleteNode(root, 4);
  cout << endl;
  inOrder(root);

  return 0;
}
