#include <iterator>

#include "iostream"
#include "set"
#include "vector"

using namespace std;
//  26: 删除有序数组中重复项
// int removeDuplicates(vector<int>& nums) {
//   set<int> setnums;
//   for (int i = 0; i < nums.size(); i++) {
//     setnums.insert(nums[i]);
//   }

//   nums.clear();  // 清空原来的元素
//   for (auto b = setnums.begin(); b != setnums.end(); b++) {
//     nums.push_back(*b);
//   }
//   return setnums.size();
// }
// 双指针解法
int removeDuplicates(vector<int>& nums) {
  int temp = 0;  // 记录
  auto p1 = nums.begin();
  auto p2 = nums.begin();
  for (; p2 != nums.end(); p2++)
    if (*p2 == *p1)
      continue;
    else {
      p1++;
      *p1 = *p2;
      temp++;
    }
  return temp + 1;
}

//  27：移除元素
int removeElement(vector<int>& nums, int val) {
  int p1 = 0, p2 = nums.size(), temp = 0;
  while (p1 != p2) {
    if (nums[p1] == val && nums[p2] != val) {
      int temp = nums[p1];
      nums[p1] = nums[p2];
      nums[p2] = temp;
      p1++;
      p2++;
    } else {
      p1++;
    }
  }
  return p1;
}

int main() {
  vector<int> vec = {1, 2};
  vector<int> vecnums2 = {0, 1, 2, 2, 5, 8};

  //   int b1 = removeDuplicates(vec);
  //   int b2 = removeDuplicates(vecnums2);
  int b1 = removeElement(vecnums2, 2);
  for (auto i : vecnums2) {
    cout << i << '\t';
  }
  cout << "结果为：" << b1 << '\t';
  return 0;
}