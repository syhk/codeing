#ifndef __LIST__HEAD
#define __LIST__HEAD

// abs List
template <typename T>
class List {
  virtual void clear() = 0;
  virtual int size() = 0;
  virtual bool isEmpty() = 0;
  virtual bool contains(T element) = 0;
  virtual void add(T element) = 0;
  //   通过下标获取元素位置
  virtual T get(int index) = 0;
  //   通过下标设置元素位置
  virtual T set(int index, T element) = 0;
  //   在 index 位置添加一个元素
  virtual void add(int index, T element) = 0;
  //   通过下标移除元素
  virtual T remove(int index) = 0;
  //   查看元素的索引
  virtual int indexOf(T element) = 0;
};

#endif  //__LIST__HEAD