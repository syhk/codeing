#include "BinarySearchTree.h"
#include "iostream"
#include "vector"
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  vector<int> vec = {7, 4, 9, 2, 5, 8, 11, 3, 12, 1};
  // cout << vec[2] << endl;
  BST<int> bst;
  for (int i : vec) {
    bst.add(i);
  }
  cout << bst.size() << endl;
  bst.PreorderTraversal();
  bst.ProTNO();
  // bst.InorderTraversal();
  // bst.PostorderTraversal();
  // bst.LevelOrderTraversal();
  // 遍历得先把左子树访问完再去访问右子树
  return 0;
}
