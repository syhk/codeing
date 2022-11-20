// BinarySearchTree
#pragma once
#include <cstdio>
#include <string>
#ifndef __BST__HEAD
#define __BST__HEAD
#include "iostream"
#include "queue"
#include "stack"

using std::cout;
using std::queue;
using std::stack;
using std::string;

// Node class
template <typename T>
class Node {
 public:
  T element;
  Node<T> *left = nullptr;
  Node<T> *right = nullptr;
  Node<T> *parent = nullptr;
  Node(T element, Node<T> *parent) : element(element), parent(parent) {}
  void nodeprint() { cout << this->element << '\t'; }
  // TODO  析构函数还没有写
};

template <typename T>
class BST {
 public:
  //  ============= 构造函数相关 ====================
  BST<T>() = default;
  // BST<T>(){};
  BST<T>(Node<T> *root) : root(root){};
  // =============== 成员函数 =======================
  // 返回元素个数
  int size();
  // 是否为空
  bool isEmpty();
  // 清空所有元素
  void clear();
  // 添加元素
  void add(T element);
  // 删除元素
  void remove(T element);
  // 是否包含某个元素
  bool contains(T element);
  // compare function
  int compare(T t1, T t2);
  // 前序遍历
  void PreorderTraversal() { this->PreT(this->root); }

  // 中序遍历
  void InorderTraversal() { this->InoT(this->root); }

  // 后序遍历
  void PostorderTraversal() { this->PosT(this->root); }
  // 层序遍历
  void LevelOrderTraversal() { this->LevT(this->root); }
  // 迭代前序
  void ProTNO() { this->ProTN(this->root); }

 private:
  // 遍历的封闭函数
  void PreT(const Node<T> *root);
  void InoT(const Node<T> *root);
  void PosT(const Node<T> *root);
  void LevT(const Node<T> *root);
  // 前序非递归
  void ProTN(Node<T> *node);
  //  元素数量
  int mysize = 0;
  // root node
  Node<T> *root = nullptr;
};

template <typename T>
/**
 * @description:
 * @return {int} 返回元素数量
 * @Author: syhk
 * @Date: 2022-10-21 08:14:12
 */
int BST<T>::size() {
  return this->mysize;
}

/**
 * @description: 是否包含某个 Node
 * @return {bool}
 * @Author: syhk
 * @Date: 2022-10-21 08:13:47
 */
template <typename T>
bool BST<T>::contains(T element) {
  return false;
}

// add Node
/**
 * @description:  add one Node
 * @return {void}
 * @Author: syhk
 * @Date: 2022-10-21 08:13:26
 */
template <typename T>
void BST<T>::add(T element) {
  // 情况一： have only root node
  if (this->root == nullptr) {
    root = new Node<T>(element, nullptr);  // 根节点没有 parent
    this->mysize++;
    return;
  }
  // 添加的不是第一个节点
  // 步骤：找到 parent ； new Node ； parent.left = node or  parent.right = node
  // 找到 parent
  Node<T> *parent = root;
  Node<T> *node = root;
  int cmp = 0;
  while (node != nullptr) {
    // cmp = this->compare(element, node->element);
    cmp = element - node->element;
    parent = node;  // 在向左或向右之前保存父节点，找到 parent
    if (cmp > 0)    // t1 > t2
    {
      node = node->right;
    } else if (cmp < 0)  // t1 < t2
    {
      node = node->left;
    } else  // t1 == t2   可以直接返回也可以覆盖
    {
      // return;
      // 如果是自定义数据类型采用覆盖方式比较好，因为比较的属性一样，但其他属性可能会不一样
      node->element = element;
      // 这里不加 break 的话，遇到相等的元素就会死循环
      break;
    }
  }

  // 找到 parent 看看插入到父节点的哪个位置(左还是右)
  Node<T> *newNode = new Node<T>(element, parent);
  if (cmp > 0) {
    parent->right = newNode;
  } else {
    parent->left = newNode;
  }
  this->mysize++;
}

/**
 * @description: 比较函数
 * @param { T} t2 t1
 * @return {int} 返回值等于 0，代表 t1 和 t2 相等； > 0 代表 t1 > t2 ； < 0 代表
 * t1 < t2
 * @Author: syhk
 * @Date: 2022-10-20 23:04:05
 */
template <typename T>
int BST<T>::compare(T t1, T t2) {
  // TODO 暂时默认为可比较类型
  return t1 - t2;
}

template <typename T>
bool BST<T>::isEmpty() {
  return this->mysize == 0;
}
template <typename T>
void BST<T>::clear() {
  this->root = nullptr;
  delete this;
  // TODO 还需要编写释放函数 delete
}
// 左右可以对调，看需求要怎么遍历
// 前： Traversal function  中--->左--->右
template <typename T>
void BST<T>::PreT(const Node<T> *node) {
  if (node == nullptr) return;
  cout << node->element << '\t';
  PreT(node->left);
  PreT(node->right);
}
// 前序遍历迭代
template <typename T>
void BST<T>::ProTN(Node<T> *node) {
  if (node == nullptr) return;
}
// 中:  左--->中--->右  or  右--->中--->左
template <typename T>
void BST<T>::InoT(const Node<T> *node) {
  if (node == nullptr) return;
  InoT(node->left);
  cout << node->element << '\t';
  InoT(node->right);
}
// 后： 左--->右--->中  or 右--->左--->中
template <typename T>
void BST<T>::PosT(const Node<T> *node) {
  if (node == nullptr) return;
  PosT(node->left);
  PosT(node->right);
  cout << node->element << '\t';
}
template <typename T>
void BST<T>::LevT(const Node<T> *node) {
  // 使用队列实现
  /*
  1.将根节点入队
  2.循环执行以下操作，直到队列为空
  - 将队头节点 A 出队，进行访问
  - 将 A 的左子节点入队
  - 将 A 的右子节点入队
  */
  if (node == nullptr) return;
  Node<T> *temp;
  queue<int> que(node);
  while (!que.empty()) {
    temp = que.pop();
    cout << temp->element << '\t';
    que.push(temp->left);
    que.push(temp->right);
  }
}
// 二叉树的顺序存储结构：只适用于满二叉树或者完全二叉树枝。
#endif  //__BST__HEAD
