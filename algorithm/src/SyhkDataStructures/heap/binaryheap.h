// 二叉堆
/*
满足的要求：
- 必须是完全二叉树枝
- 二叉堆中的每一个节点，都必须大于等于（或小于等于）其子树中每个节点的值
分为：大顶堆和小顶堆
底层实现：数组
索引 i 的规律
- 如果  i = 0 ,它是根节点
n 是元素的数量
- 如果  i > 0 ,它的父节点编号为 floor((i-1) >> 1)
- 如果 2i+1 <= n - 1 它的左子节点编号为 2i+1
- 如果 2i+1 > n - 1 , 它无左子节点

- 如果 2i+2 <= n - 1 它的右子节点编号为 2i+2
- 如果 2i+2 > n - 1 , 它无右子节点
*/
#ifndef __BINARYHEAP_H
#define __BINARYHEAP_H
#include <stdio.h>

#include "iostream"
#include "vector"

using namespace std;

class BinHeap {
 public:
  int size();
  void clear();
  int get();           // 拿到根元素
  int remove();        // 删除堆顶元素
  int replace(int e);  // 删除堆顶元素的同时插入一个新元素
  void add(int e);     // 添加元素
  bool isEmpty();      // 是否为空
  void printBH();
  void heapify1();
  void heapify2();
  BinHeap(vector<int> vec) : nums(vec) {
    // question: 直接在传递进来的数组进建堆，那么外部改变了数组就会破坏堆结构
    // solve :
    // 可以将传递进来的数组进行拷贝，不直接在原地建堆,这样外面更改就不会影响到堆结构
    heapify2();
    cout << "构造函数： " << nums.size() << endl;
  }
  BinHeap() = default;

 private:
  void siftup(int index);    // 让 index 位置上的元素上滤
  void siftdown(int index);  // 让 index 位置上的元素上滤
  void emptyCheck() {
    if (nums.size() == 0) throw "当前没有元素";
  }
  vector<int> nums;
};
inline int BinHeap::size() { return nums.size(); }
inline void BinHeap::clear() { nums.clear(); }
inline bool BinHeap::isEmpty() { return nums.empty(); }
inline int BinHeap::remove() {
  //  删除就是删除堆顶元素
  // 思路：
  /*
  - 用最后一个节点覆盖根节点
  - 删除最后一个节点
  - 循环执行以下操作：
    - if node < 子节点
      与最大的子节点交换位置
    - if node >= 子节点 or 没有子节点
    退出循环
  */
  // 这个过程叫 下滤 （Sift Down) O(logn)
  emptyCheck();
  int root = nums[0];  // 记录堆顶元素进行返回
  nums[0] = nums[size() - 1];
  siftdown(0);
  cout << "remove 删除的元素为 :" << root << endl;
  return root;
}
// index 位置元素进行 下滤
inline void BinHeap::siftdown(int index) {
  // 第一个非叶子节点的索引 ==  非叶子节点的数量
  //  非叶子节点的数量 ： floor(n/2)
  int half = size() >> 1;
  int e = nums[index];
  // index < 第一个叶子节点的索引
  while (index < half) {  // 保证 index 位置是非叶子节点
    // index 的节点只有两种情况： 1.只有左子节点 2.同时有左右子节点
    // 默认为左子节点跟它比较
    int childIndex = (index << 1) + 1;
    int child = nums[childIndex];
    // 右子节点
    int rightIndex = childIndex + 1;
    // 选出左右子节点最大的那个
    if (rightIndex < size() && (nums[rightIndex] - child) > 0) {
      childIndex = rightIndex;
      child = nums[rightIndex];
    }
    if ((e - child) >= 0) break;
    // 将子节点存放到 index 位置
    nums[index] = child;
    // 重新设置 index
    index = childIndex;
  }
  nums[index] = e;
}
// 最大堆（大顶堆）
inline void BinHeap::add(int e) {
  // 循环执行：
  // 如果 e > 父节点---> 与父节点交换位置
  // 如果 e <= 父节点 or 没有父节点 ---> 退出循环
  // 以上过程叫  上滤 (Sift up) 时间复杂度为  O(logn)
  nums.push_back(e);
  siftup(size() - 1);
}
// // 上滤
// inline void BinHeap::siftup(int index) {
//   int e = nums[index];
//   while (index > 0) {
//     int pindex = (index - 1) >> 1;  // 父节点
//     int p = nums[pindex];
//     if ((e - p) <= 0) return;

//     // 交换 index 和 pindex 的内容

//     swap(nums[index], nums[pindex]);
//     index = pindex;
//   }
// }
// 优化： 记录新增加的节点，确定最终位置再覆盖
inline void BinHeap::siftup(int index) {
  int e = nums[index];
  while (index > 0) {
    int pindex = (index - 1) >> 1;  // 父节点
    int p = nums[pindex];
    if ((e - p) <= 0) break;
    // 将父元素存储在 index 位置
    nums[index] = p;

    index = pindex;
  }
  nums[index] = e;
}

inline int BinHeap::replace(int e) {
  int root = 0;
  if (size() == 0)  // 第一个元素
  {
    nums[0] = e;
  } else {
    root = nums[0];
    nums[0] = e;
    siftdown(0);  // O(logn)
  }

  // int root = remove();
  // add(e);
  // 上面两个操作 O(n) ,复杂度太高
  cout << "replace 删除的元素为 :" << root << endl;
  return root;
}
inline int BinHeap::get() {
  try {
    emptyCheck();
  } catch (const char *c) {
    cout << "捕获到一个异常： " << c << endl;
  }
  return nums[0];
}
inline void BinHeap::printBH() {
  for (auto i : nums) {
    cout << i << '\t';
  }
}

// 批量建堆   heapify
// 两种做法： 自上而下  自下而上
// 自上而下的上滤 O(nlogn)
inline void BinHeap::heapify1() {
  for (int i = 1; i < nums.size() - 1; i++) {
    siftup(i);
  }
}
// 自下而上的下滤 批量建堆：这个效率比较高，比上面那个好 O(n)
inline void BinHeap::heapify2() {
  for (int i = (nums.size() >> 1) - 1; i >= 0; i--) {
    siftdown(i);
  }
}

/*
question:  自上而下的下滤，自下而上的上滤不可以批量建堆



*/

#endif  //__BINARYHEAP_H