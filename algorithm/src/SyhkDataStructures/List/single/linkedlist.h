// 单向链表
#pragma once
#include <malloc.h>
#include <string.h>

#include "iostream"
#include "list.h"
#include "new"

using std::cout;

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
  Node<T>* node = head;
  while (node != nullptr) {
    cout << node->element << "-->";
    node = node->next;
  }
  cout << "nullptr" << '\n';
}

template <typename T>
class linkedlist : public List<T> {
 public:
  linkedlist() = default;
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
  Node<T>* head = nullptr;

  int mysize = 0;
};

template <typename T>
void linkedlist<T>::clear() {
  // TODO 析构函数释放内存空间还没有写
  this->mysize = 0;
  this->head->next = nullptr;
  cout << "调用了析构函数" << std::endl;
  delete head;
}

template <typename T>
int linkedlist<T>::size() {
  return this->mysize;
}
template <typename T>
bool linkedlist<T>::isEmpty() {
  return this->mysize == 0 ? true : false;
}

template <typename T>
bool linkedlist<T>::contains(T element) {
  if (this->head == nullptr) return false;
  Node<T>* node = this->head;
  while (node != nullptr) {
    if (node->element == element) return true;
    node = node->next;
  }
  return false;
}

template <typename T>
void linkedlist<T>::add(T element) {
  Node<T>* newnode = nullptr;
  Node<T>* prevnode = nullptr;
  if (head == nullptr) {
    newnode = new Node<T>(element, nullptr);
    // newnode->next = head;
    head = newnode;
  } else {
    prevnode = nodefind(this->size() - 1);
    //  先连后断
    newnode = new Node<T>(element, prevnode->next);
    prevnode->next = newnode;
  }
  //   别忘了 size++
  this->mysize++;
}

template <typename T>
T linkedlist<T>::get(int index) {
  return nodefind(index)->element;
}

// 返回修改前的值
template <typename T>
T linkedlist<T>::set(int index, T element) {
  Node<T>* node = nodefind(index);
  T old = node->element;
  node->element = element;
  return old;
}

template <typename T>
void linkedlist<T>::add(int index, T element) {
  Node<T>* newnode = nullptr;
  Node<T>* prevnode = nullptr;
  // 如果传递进来的是 0 就是添加到最前面
  if (index == 0) {
    newnode = new Node<T>(element, this->head);
    this->head = newnode;
  }
  //   else if (index == this->mysize) {
  //     prevnode = nodefind(index);
  //     newnode = new Node<T>(element, nullptr);
  //     prevnode->next = newnode;

  //   }
  else {
    prevnode = nodefind(index - 1);
    //  先连后断
    newnode = new Node<T>(element, prevnode->next);
    prevnode->next = newnode;
  }
  //   别忘了 size++
  this->mysize++;
  cout << "head: " << this->head->element << '\n';
}

// 返回被删除节点的值
template <typename T>
T linkedlist<T>::remove(int index) {
  // 注意边界值
  // if (index == this->mysize) index--;  // 处理一下删除最后一个元素
  Node<T>* node = this->head;
  if (index == 0) {
    this->head = this->head->next;
  } else {
    Node<T>* prev = nodefind(index - 1);
    node = prev->next;
    prev->next = prev->next->next;
  }
  this->mysize--;
  return node->element;
}

// 返回元素首次出现的下标
template <typename T>
int linkedlist<T>::indexOf(T element) {
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
Node<T>* linkedlist<T>::nodefind(int index) {
  rangeCheck(index);

  Node<T>* node = this->head;
  for (int i = 0; i < index; i++) {
    node = node->next;
  }
  return node;
}

template <typename T>
Node<T>* linkedlist<T>::reverseList(Node<T>* node) {
  // TODO 这个有问题后面现改
  if (node == nullptr || node->next == nullptr)
    return node;  // 链表为空 或 只有一个节点
  Node<T>* newnode = reverseList(node->next);
  node->next->next = node;
  node->next = nullptr;
  return newnode;
}

template <typename T>
void linkedlist<T>::rangeCheck(int index) {
  if (index < 0 || index > this->mysize) {
    throw "index 有误!!!";
  }
}
