#include <ios>

#include "iostream"
// #include "linkedlist.h"
#include "doublelinkedlist.h"

using std::cout;
using std::endl;

int main(void) {
  linkedlist<int> li;
  li.add(12);
  li.add(13);
  li.add(13);
  li.add(13);
  // li.add(0, 88);
  // li.add(0, 99);
  // li.add(li.size(), 520);
  // li.remove(2);
  // // li.add(1001);
  // cout << li.size() << endl;
  // // // size 是实际长度 > 1
  // li.remove(li.size() - 1);
  // // li.reverseList(li.gethead());

  li.print();
  // li.print();
  // cout << li.size() << endl;
  // cout << std::boolalpha << endl;
  // cout << li.contains(99) << "   " << li.contains(000) << endl;
  // cout << li.indexOf(99) << "    " << li.indexOf(13) << endl;
  // cout << li.get(li.indexOf(13)) << endl;

  return 0;
}