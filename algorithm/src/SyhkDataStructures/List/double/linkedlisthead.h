// 单向链表
#ifndef __LINKEDLISTHEAD__H
#define __LINKEDLISTHEAD__H
#include <malloc.h>
#include <string.h>

#include "iostream"
#include "list.h"
#include "new"

using std::cout;

// ------------------->   增加一个虚拟头结点
// TODO 双向链表带头还没有写
// Node
template <typename T>
class Node {
 public:
  Node(T element, Node<T>* node) : element(element), next(node) {}
  Node() = default;
  T element;
  Node<T>* next = nullptr;
};

template <typename T>
void printlist(Node<T>* head) {
  Node<T>* node = head->next;
  while (node != nullptr) {
    cout << node->element << "-->";
    node = node->next;
  }
  cout << "nullptr" << '\n';
}

template <typename T>
class linkedlisthead : public List<T> {
 public:
  linkedlisthead() = default;
  void clear();
  int size();
  bool isEmpty();
  bool contains(T element);
  void add(T element);
  T get(int index);
  T set(int index, T element);
  void add(int index, T element);
  T remove(int index);
  int indexOf(T element);
  void print() { printlist<>(this->head); }
  Node<T>* gethead() { return head; }
  // 反转链表 递归实现
  Node<T>* reverseList(Node<T>* head);

 private:
  void rangeCheck(int index);
  //  这个友元函数需要加 <> : 表示它是一个模板函数
  friend void printlist<>(Node<T>* head);

  // 找到 index 的前一个结点
  Node<T>* nodefind(int index);
  //  维护一个 head node
  Node<T>* head = new Node<T>(0, nullptr);

  int mysize = 0;
};

template <typename T>
void linkedlisthead<T>::clear() {
  // TODO 析构函数释放内存空间还没有写
  this->mysize = 0;
}

template <typename T>
int linkedlisthead<T>::size() {
  return this->mysize;
}
template <typename T>
bool linkedlisthead<T>::isEmpty() {
  return this->mysize == 0 ? true : false;
}

template <typename T>
bool linkedlisthead<T>::contains(T element) {
  if (this->head->next == nullptr) return false;
  Node<T>* node = this->head;
  while (node != nullptr) {
    if (node->element == element) return true;
    node = node->next;
  }
  return false;
}

template <typename T>
void linkedlisthead<T>::add(T element) {
  Node<T>* newnode = nullptr;
  Node<T>* prevnode = nullptr;
  if (head == nullptr) {
    newnode = new Node<T>(element, nullptr);
    // newnode->next = head;
    head = newnode;
  } else {
    prevnode = this->mysize == 0 ? this->head : nodefind(this->size() - 1);
    //  先连后断
    newnode = new Node<T>(element, prevnode->next);
    prevnode->next = newnode;
  }
  //   别忘了 size++
  this->mysize++;
}

template <typename T>
T linkedlisthead<T>::get(int index) {
  return nodefind(index)->element;
}

// 返回修改前的值
template <typename T>
T linkedlisthead<T>::set(int index, T element) {
  Node<T>* node = nodefind(index);
  T old = node->element;
  node->element = element;
  return old;
}

template <typename T>
void linkedlisthead<T>::add(int index, T element) {
  Node<T>* newnode = nullptr;
  Node<T>* prevnode = nullptr;
  //   TODO 改动位置
  prevnode = index == 0 ? this->head : nodefind(index - 1);
  //  先连后断
  newnode = new Node<T>(element, prevnode->next);
  prevnode->next = newnode;
  //   别忘了 size++
  this->mysize++;
  cout << "head: " << this->head->element << '\n';
}

// 返回被删除节点的值
template <typename T>
T linkedlisthead<T>::remove(int index) {
  // 注意边界值
  // if (index == this->mysize) index--;  // 处理一下删除最后一个元素
  Node<T>* node = this->head;
  Node<T>* prev = index == 0 ? node : nodefind(index - 1);
  node = prev->next;
  prev->next = prev->next->next;
  this->mysize--;
  return node->element;
}

// 返回元素首次出现的下标
template <typename T>
int linkedlisthead<T>::indexOf(T element) {
  if (this->head == nullptr) return -1;
  int i = 0;
  Node<T>* node = this->head;
  while (node != nullptr) {
    if (node->element == element) return i;
    node = node->next;
    i++;
  }
  return -1;
}

template <typename T>
Node<T>* linkedlisthead<T>::nodefind(int index) {
  rangeCheck(index);

  Node<T>* node = this->head->next;
  for (int i = 0; i < index; i++) {
    node = node->next;
  }
  return node;
}

template <typename T>
Node<T>* linkedlisthead<T>::reverseList(Node<T>* node) {
  // TODO 这个有问题后面现改
  if (node == nullptr || node->next == nullptr)
    return node;  // 链表为空 或 只有一个节点
  Node<T>* newnode = reverseList(node->next);
  node->next->next = node;
  node->next = nullptr;
  return newnode;
}

template <typename T>
void linkedlisthead<T>::rangeCheck(int index) {
  if (index < 0 || index > this->mysize) {
    throw "index 有误!!!";
  }
}

#endif  //__LINKEDLISTHEAD__H