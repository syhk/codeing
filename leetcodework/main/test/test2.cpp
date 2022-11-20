#include <algorithm>

#include "iostream"
#include "math.h"
#include "vector"

using namespace std;

//   leetcode => 1143
//  求两个序列的最长公共子序列长度

int lcs(vector<int>& nus1, vector<int>& nums2);
int lcs_recursion(vector<int>& nums1, int i, vector<int>& nums2, int j);
int lcs2(vector<int>& nums1, vector<int>& nums2);
int lcs3(vector<int>& nums1, vector<int>& nums2);
int lcs4(vector<int>& nums1, vector<int>& nums2);
int lcs5(vector<int>& nums1, vector<int>& nums2);
int main(void) {
  // 下面不能是： 1,4,5,9,10,13
  vector<int> nums1 = {1, 4, 5, 9, 10, 12, 13};
  vector<int> nums2 = {1, 4, 9, 10, 13, 5};
  cout << lcs(nums1, nums2) << endl;
  cout << lcs2(nums1, nums2) << endl;
  cout << lcs3(nums1, nums2) << endl;
  cout << lcs4(nums1, nums2) << endl;
  cout << lcs5(nums1, nums2) << endl;
}

// 思路
int lcs(vector<int>& nums1, vector<int>& nums2) {
  //  状态： dp(i,j) ===>  nums1 前 i 个元素和 nums2 前 j
  //  个元素的最长子序列公共长度 i,j 取值范围： i --> 0,nums1.length  j -->
  //  0,nums2.length
  /*eg:
  nums1: 1,3,5,9,10
  nums2:1,4,9,10
  --------------->
  1,3
  1,4,9
  dp(2,3)= 1
  dp(4,4)= 2
  最终解： dp(nums1.length,nums2.length)
  */

  // 初始状态 ： dp(i,0) dp(0,j) 初始值均为 0
  // 状态转移：
  // nums1[i - 1]=nums2[j - 1] ---->  dp(i,j) = dp(i-1,j-1)+1
  // nums1[i - 1]!= nums2[j - 1] ----> dp(i,j) = max(dp(i-1,j),dp(i,j-1))

  if (nums1.size() == 0 || nums2.size() == 0) return 0;

  return lcs_recursion(nums1, nums1.size(), nums2, nums2.size());
}
// return： nums1 前 i 个元素 和  nums2  前 j 个元素最长公共子序列长度

int lcs_recursion(vector<int>& nums1, int i, vector<int>& nums2, int j) {
  if (i == 0 || j == 0) return 0;
  if (nums1[i - 1] == nums2[j - 1]) {  // ==
    return lcs_recursion(nums1, i - 1, nums2, j - 1) + 1;
  }

  return max(lcs_recursion(nums1, i - 1, nums2, j),
             lcs_recursion(nums1, i, nums2, j - 1));
}

// no recursion

int lcs2(vector<int>& nums1, vector<int>& nums2) {
  if (nums1.size() == 0 || nums2.size() == 0) return 0;
  //    dp
  //    数组开辟空间大小，只每次计算只需要保留对于下次计算有用的数据即可，其他没用的数据全部丢弃
  // 分析：找到本次结果和上次计算结果的关系，需要前面几次的数据，还是需要前面所有计算结果的数据
  int dp[nums1.size() + 1][nums2.size() + 1];
  //  初始化为0
  for (int i = 0; i < nums1.size(); i++) {
    for (int j = 0; j < nums2.size(); j++) {
      dp[i][j] = 0;
    }
  }

  //  从 o 开始没有任何意义
  for (int i = 1; i <= nums1.size(); i++) {
    for (int j = 1; j <= nums2.size(); j++) {
      if (nums1[i - 1] == nums2[j - 1])  // ==
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {  // !=
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[nums1.size()][nums2.size()];
}
//  dp 一定要注意 重复计算  , 一定要避免
//  move window  二维
int lcs3(vector<int>& nums1, vector<int>& nums2) {
  if (nums1.size() == 0 || nums2.size() == 0) return 0;
  //    dp
  //    数组开辟空间大小，只每次计算只需要保留对于下次计算有用的数据即可，其他没用的数据全部丢弃
  // 分析：找到本次结果和上次计算结果的关系，需要前面几次的数据，还是需要前面所有计算结果的数据
  int dp[2][nums2.size() + 1];
  //  初始化为0
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < nums2.size(); j++) {
      dp[i][j] = 0;
    }
  }

  //  从 o 开始没有任何意义
  for (int i = 1; i <= nums1.size(); i++) {
    //  模 2 可以用 & 或 1 来实现等效的功能
    // int row = i % 2;
    int row = i & 1;
    // int prevrow = (i - 1) % 2;
    int prevrow = (i - 1) & 1;
    for (int j = 1; j <= nums2.size(); j++) {
      if (nums1[i - 1] == nums2[j - 1])  // ==
      {
        dp[row][j] = dp[prevrow][j - 1] + 1;
      } else {  // !=
        dp[row][j] = max(dp[prevrow][j], dp[row][j - 1]);
      }
    }
  }
  return dp[nums1.size() & 1][nums2.size()];
}

//  move window  一维 : 利用不断覆盖
int lcs4(vector<int>& nums1, vector<int>& nums2) {
  if (nums1.size() == 0 || nums2.size() == 0) return 0;
  int dp[nums2.size() + 1];
  //  初始化为0
  for (int i = 0; i < nums2.size(); i++) dp[i] = 0;
  //  从 o 开始没有任何意义 ,因为它都是返回 0
  for (int i = 1; i <= nums1.size(); i++) {
    int cur = 0;
    for (int j = 1; j <= nums2.size(); j++) {
      int leftTop = cur;  // 保留左上角的值
      cur = dp[j];
      if (nums1[i - 1] == nums2[j - 1])  // ==
      {
        dp[j] = dp[j - 1] + 1;
      } else {  // !=
        dp[j] = max(dp[j], dp[j - 1]);
      }
    }
  }
  return dp[nums2.size()];
}

//  （优化空间复杂度）还要度优化，一维数组空间大小为 两个数组之中容量比较小的
int lcs5(vector<int>& nums1, vector<int>& nums2) {
  if (nums1.size() == 0 || nums2.size() == 0) return 0;
  vector<int> rowsNums = nums1;
  vector<int> colsNums = nums2;
  if (nums1.size() < nums2.size()) {
    colsNums = nums1;
    rowsNums = nums2;
  }
  int dp[colsNums.size() + 1];

  for (int i = 1; i <= rowsNums.size(); i++) {
    int cur = 0;

    for (int j = 1; j <= colsNums.size(); j++) {
      int leftTop = cur;
      cur = dp[j];
      if (rowsNums[i - 1] == colsNums[j - 1]) {
        dp[j] = leftTop + 1;
      } else {
        dp[j] = max(dp[j], dp[j - 1]);
      }
    }
  }
  return dp[colsNums.size()];
}
