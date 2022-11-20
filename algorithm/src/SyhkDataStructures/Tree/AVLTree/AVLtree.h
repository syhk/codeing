#pragma once
#include <cstdio>
#include <string>

#include "iostream"
#include "list"

using namespace std;

class AVLNode {
 public:
  int key = 0;
  AVLNode *left = nullptr;
  AVLNode *right = nullptr;
  int depth = 0;
};

inline int max(int a, int b) { return (a > b) ? a : b; }

inline int depth(AVLNode *n) {
  if (n == nullptr) return 0;
  return n->depth;
}

inline AVLNode *newNode(int key) {
  AVLNode *node = new AVLNode();
  node->key = key;
  node->left = nullptr;
  node->right = nullptr;
  node->depth = 1;
  return node;
}

// right rotate
inline AVLNode *rightRotate(AVLNode *root) {
  AVLNode *x = root->left;
  AVLNode *T2 = x->right;

  // 执行旋转
  x->right = root;
  root->left = T2;

  // update heights
  root->depth = max(depth(root->left), depth(root->right)) + 1;
  x->depth = max(depth(x->left), depth(x->right)) + 1;
  return x;
}

// left rotate
inline AVLNode *leftRotate(AVLNode *root) {
  AVLNode *y = root->right;
  AVLNode *T2 = y->left;

  // 执行旋转
  y->left = root;
  root->right = T2;

  // update heights
  root->depth = max(depth(root->left), depth(root->right)) + 1;
  y->depth = max(depth(y->left), depth(y->right)) + 1;

  return y;
}

inline int getBalance(AVLNode *N) {
  if (N == nullptr) {
    return 0;
  }
  return depth(N->left) - depth(N->right);
}

inline AVLNode *insert(AVLNode *node, int key) {
  if (node == nullptr) return (newNode(key));

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  else
    return node;

  node->depth = 1 + max(depth(node->left), depth(node->right));

  int balance = getBalance(node);

  //   Left  Left Case
  if (balance > 1 && key < node->left->key) return rightRotate(node);
  // 	 Right Right Case
  if (balance < -1 && key > node->right->key) return leftRotate(node);
  //   Left Right Case
  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  // 	Right Left Case
  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
  return node;
}

inline AVLNode *minValueNode(AVLNode *node) {
  AVLNode *current = node;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current;
}

inline AVLNode *deleteNode(AVLNode *root, int key) {
  if (root == nullptr) return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if ((root->left) == nullptr || (root->right) == nullptr) {
      AVLNode *temp = root->left ? root->left : root->right;
      if (temp == nullptr) {
        temp = root;
        root = nullptr;
      } else
        *root = *temp;  // One child case
      free(temp);
    } else {
      AVLNode *temp = minValueNode(root->right);
      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == nullptr) return root;

  root->depth = 1 + max(depth(root->left), depth(root->right));

  int balance = getBalance(root);

  // LL
  if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
  // LR
  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  // RR
  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  // RL
  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}
 
inline void inOrder(AVLNode *root) {
  if (root != nullptr) {
    inOrder(root->left);
    cout << root->key << "   ";
    inOrder(root->right);
  }
}
