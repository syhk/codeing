// ----------------^^^^^-----------------------
//  定义状态： 定义 dp(i)
// 设置初始状态： 设置 dp(0) 的值
// 确定状态转换方程：确定 dp(i) 和 dp(i-1)的关系
// ----------------^^^^^-----------------------
// 将复杂的原问题拆解为若干个子问题
// 每个子问题只解决 1 次，并保存它们的解
// 最后导出原问题的解
// 解决问题具备的特点：
// - 最优子结构（最优化原理）： 通过求解子问题的最优解，可以获得原问题的最优解
// -
// 无后效性：某阶段的状态一旦确定，则此后过程的演变不再受此前各状态及决策的影响（未来与过去无关）
//  		 -
//  在推导后面的阶段的状态时，只关心前面阶段的具体状态值，不关心这个状态是怎么一步步推导出来的

// eg: 最大连续子序列和
#include "iostream"
#include "vector"
using namespace std;
int maxSubArray1(int nums[], int length);
int maxSubArray(int nums[], int length);
int LCS(int nums1[], int nums2[]);
int LIS(int nums[], int length);
void quicksort(int nums, int length);
void sort(int begin, int end);
int pivotIndex(int begin, int end);

int main(void) {
  //  -2 1 -3 4 -1 2 1 -5 4 在最在连续子序列和是  4+(-1)+2+1 = 6

  int nums[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << maxSubArray(nums, 9);
}

// 初始状态  dp(0) = nums[0]

int maxSubArray1(int nums[], int length) {
  if (nums == nullptr) return 0;
  if (length <= 0) return 0;

  int dp[length];
  for (int i = 0; i < length; i++) {
    dp[i] = 0;
  }

  dp[0] = nums[0];

  int max = dp[0];
  for (int i = 0; i < length; i++) {
    if (dp[i - 1] <= 0) {
      dp[i] = nums[i];
    } else {
      dp[i] = dp[i - 1] + nums[i];
    }
    max = dp[i] > max ? dp[i] : max;
  }
  return max;
}

// 优化思路：不需要记录以前的结果，可以丢弃，只需要一个变量，滚动数组
int maxSubArray(int nums[], int length) {
  int dp = nums[0];

  int max = dp;
  for (int i = 0; i < length; i++) {
    if (dp <= 0) {
      dp = nums[i];
    } else {
      dp = dp + nums[i];
    }
    max = dp > max ? dp : max;
  }
}

/*
// 大的才拥抱，小的是拖后腿的（大的加大，小的在加小）
if (dp[i-1] <= 0){
        dp[i] = nums[i]
}else {
        dp[i]= dp[i-1]+nums[i]
}

*/

// 最长上升子序列
// 给定一个无序的整数序列，求它的最长上升子序列
// eg: 10, 2 , 2 ,5 ,1 , 7 , 101, 18  最长上升子序列是：  2,5,7,101  2,5,7,18
// 长度为 4

// eg: 初始状态 dp(0) = nums[10] = 1
// 需要保存之前的 dp ， 要找长的接上才能更长
// 需要当前元素前面的所有元素
// 所有的 dp(i) 都默认初始为 1

// 步骤：
//  遍历： j 属于 [0,i)
//  nums[i] > nums[j]

//  nums[i] < nums[j]
int LIS(int nums[], int length) {
  //  10 , 2 , 2 , 5 , 1 , 7 , 101  , 18
}

// LCS 最长公共子序列
//  nums1: 1,3,5,9,10   nums2:1,4,9,10   ===>  1,9,10
int LCS(int nums1[], int nums2[]) {}
