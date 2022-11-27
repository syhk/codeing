// Morris
#include "iostream"
using namespace std;

struct Node {
  int data;
  struct Node* left_node;
  struct Node* right_node;
};

void Morris(struct Node* root) {
  struct Node *curr, *prev;
  if (root == nullptr) {
    return;
  }
  curr = root;
  while (curr != nullptr) {
    if (curr->left_node == nullptr) {
      cout << curr->data << endl;
      curr = curr->right_node;
    } else {
      prev = curr->left_node;
      while (prev->right_node != nullptr && prev->right_node != curr) {
        prev = prev->right_node;
      }
      if (prev->right_node == nullptr) {
        prev->right_node = curr;
        curr = curr->left_node;
      } else {
        prev->right_node = nullptr;
        cout << curr->data << endl;
        curr = curr->right_node;
      }
    }
  }
}
struct Node* add_node(int data) {
  struct Node* node = new Node;
  node->data = data;
  node->left_node = nullptr;
  node->right_node = nullptr;
  return node;
}
int main() {
  struct Node* root = add_node(4);
  root->left_node = add_node(2);
  root->right_node = add_node(5);
  root->left_node->left_node = add_node(1);
  root->right_node->right_node = add_node(3);
  Morris(root);
  return 0;
}