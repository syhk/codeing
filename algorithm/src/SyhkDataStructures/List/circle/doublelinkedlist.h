// 双向循环链表
#pragma once
#include <malloc.h>
#include <string.h>

#include "iostream"
#include "list.h"
#include "new"

using std::cout;
// 双向 list　的 prev 和 next 不会为 nullptr
// Node
template <typename T>
class Node {
 public:
  Node(Node<T>* prev, T element, Node<T>* next)
      : prev(prev), element(element), next(next) {}
  Node() = default;
  T element;
  Node<T>* next = nullptr;
  Node<T>* prev = nullptr;
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
  void print() { printlist<>(this->first); }
  Node<T>* gethead() { return head; }

 private:
  void rangeCheck(int index);
  //  这个友元函数需要加 <> : 表示它是一个模板函数
  friend void printlist<>(Node<T>* head);

  // 找到 index 的前一个结点
  Node<T>* nodefind(int index);
  //  维护一个 head node
  Node<T>* head = nullptr;
  Node<T>* first = nullptr;
  Node<T>* last = nullptr;

  int mysize = 0;
};

template <typename T>
void linkedlist<T>::clear() {
  // TODO 析构函数释放内存空间还没有写
  this->mysize = 0;
  this->head->next = nullptr;
  this->head->prev = nullptr;
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
  // add first node
  if (mysize == 0) {
    Node<T>* node = new Node<T>(nullptr, element, nullptr);
    first = last = node;
    mysize++;
  } else {
    add(this->mysize, element);
  }
}

template <typename T>
T linkedlist<T>::get(int index) {
  return nodefind(index)->element;
}

// return alter befor value
template <typename T>
T linkedlist<T>::set(int index, T element) {
  Node<T>* node = nodefind(index);
  T old = node->element;
  node->element = element;
  return old;
}

template <typename T>
void linkedlist<T>::add(int index, T element) {
  rangeCheck(index);
  // index == 0   size == 0
  if (index == mysize) {  //  add end node
    Node<T>* oldlast = last;
    // TODO alter
    last = new Node<T>(oldlast, element, first);
    if (oldlast == nullptr) {  // add first
      first = last;
      // TODO alter
      first->next = first;
      first->prev = first;
    } else {
      oldlast->next = last;
      // TODO alter
      first->prev = last;
    }

  } else {
    Node<T>* next = nodefind(index);
    Node<T>* prev = next->prev;
    Node<T>* node = new Node<T>(prev, element, next);
    next->prev = node;
    prev->next = node;
    // TODO alter
    if (index == 0) {  // index == 0
      this->first = node;
    }
  }
  mysize++;
}

template <typename T>
T linkedlist<T>::remove(int index) {
  rangeCheck(index);
  // have only one node
  Node<T>* node = first;
  if (mysize == 1) {
    first = last = nullptr;
  }

  node = nodefind(index);
  Node<T>* prev = node->prev;
  Node<T>* next = node->next;

  prev->next = next;
  next->prev = prev;
  if (node == first) {  // index == 0
    first = next;
  }
  if (node == last)  // index == size - 1
  {
    last = prev;
  }
  mysize--;

  return node->element;
}

template <typename T>
Node<T>* linkedlist<T>::nodefind(int index) {
  rangeCheck(index);
  // 双向可以分情况提高查找效率
  if (index == 0) {
    return first;
  }
  Node<T>* node = nullptr;

  if (index < (mysize >> 1)) {  // 在前半部分
    node = this->first->next;
    for (int i = 0; i < index; i++) {
      node = node->next;
    }
  } else {  // 在后半部分
    node = this->last;
    for (int i = mysize - 1; i > index; i--) {
      node = node->prev;
    }
  }
  return node;
}

template <typename T>
void linkedlist<T>::rangeCheck(int index) {
  if (index < 0 || index > this->mysize) {
    throw "index 有误!!!";
  }
}

template <typename T>
int linkedlist<T>::indexOf(T element) {
  return 0;
}