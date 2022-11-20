#include <ios>

#include "iostream"
#include "linkedlist.h"
// #include "linkedlisthead.h"

using std::cout;
using std::endl;

int main(void) {
  linkedlist<int> li;
  li.add(12);
  li.add(13);
  li.add(13);
  li.add(13);
  li.add(0, 88);
  li.add(0, 99);
  li.add(li.size(), 520);
  li.add(1001);
  li.print();
  // cout << li.size() << endl;
  // // size 是实际长度 > 1
  // li.remove(li.size() - 1);
  // li.reverseList(li.gethead());

  // li.print();
  // cout << li.size() << endl;
  // cout << std::boolalpha << endl;
  // cout << li.contains(99) << "   " << li.contains(000) << endl;
  // cout << li.indexOf(99) << "    " << li.indexOf(13) << endl;
  // cout << li.get(li.indexOf(13)) << endl;
  // cout << "---------------^^^^^-----------------------" << endl;
  // linkedlisthead<int> list;
  // list.add(10);
  // list.add(14);
  // list.add(10);
  // list.add(10);
  // list.add(0, 1001);
  // list.remove(2);
  // list.print();

  return 0;
}