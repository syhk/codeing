#include <vector>

#include "binaryheap.h"

int main() {
  //  小顶可直接更改大顶堆的比较策略就可以（反过来比较）；
  BinHeap bh;
  bh.add(68);
  bh.add(72);
  bh.add(43);
  bh.add(50);
  bh.add(38);
  bh.add(10);
  bh.add(90);
  bh.add(65);
  //   bh.remove();
  //   bh.remove();
  //   bh.replace(150);
  //   bh.printBH();
  cout << endl;
  vector<int> nums = {68, 72, 43, 50, 38, 10, 90, 65};
  //   BinHeap bh1(nums);
  //   bh1.printBH();

  BinHeap heap;
  // question: 找出最小的前 k 个数
  // question: 找出最大的前 k 个数
  int k = 5;
  vector<int> topk = {51, 30, 39, 92, 74, 25, 16, 93, 91, 19, 54, 47, 73,
                      62, 76, 63, 35, 18, 90, 6,  65, 49, 26, 61, 21, 48};
  for (int i = 0; i < topk.size() - 1; i++) {
    if (heap.size() < k) {  // 前 k 个数添加到小顶堆
      heap.add(topk[i]);
    } else if (topk[i] > heap.get()) {  // 如果是第 k + 1 个数,并且大于堆顶元素
      heap.replace(topk[i]);
    }
  }
  heap.printBH();
}