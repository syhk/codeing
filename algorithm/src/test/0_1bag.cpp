#include "iostream"
#include "math.h"
#include "vector"

using namespace std;
int process(vector<int> w, vector<int> v, int index, int bag);
int dp(vector<int> w, vector<int> v, int bag);
//  所有的货，重量和价值，都在 w 和  v 数组中
// bag 背包容量，不能超过载重
// 返回： 不超重的情况下，能够得到的最价值
int maxValue(vector<int>& w, vector<int>& v, int bag) {
  if (w.size() != v.size() || w.size() == 0) {
    return 0;
  }
  //   return process(w, v, 0, bag);
  return dp(w, v, bag);
}

// 当前考虑到了 index 货物，index...所有货物都可以自由选择
// 做的选择不能超过背包容量
// 返回最大价值
int process(vector<int> w, vector<int> v, int index, int bag) {
  if (bag < 0) {  // bag 已经小于0 了
    return -1;
  }
  if (index == w.size()) {  // 没有物品可以选择了
    return 0;
  }
  // index 没到最后，货，index位置的货
  // bag 有空间，0
  // 不要当前的货
  int p1 = process(w, v, index + 1, bag);

  // 要当前的货
  int p2 = 0;
  int next = process(w, v, index + 1, bag - w[index]);
  if (next != -1) {
    p2 = v[index] + next;
  }
  return p1 > p2 ? p1 : p2;
}

int dp(vector<int> w, vector<int> v, int bag) {
  if (w.size() != v.size() || w.size() == 0) {
    return 0;
  }

  int N = w.size();
  int dp[N + 1][bag + 1];
  for (int i = 0; i < N; i++) {
    dp[N][i] = 0;
  }
  for (int index = N - 1; index >= 0; index--) {
    for (int rest = 0; rest <= bag; rest++) {
      int p1 = dp[index + 1][rest];
      int p2 = 0;
      int next = rest - w[index] < 0 ? -1 : dp[index + 1][rest - w[index]];
      if (next != -1) {
        p2 = v[index] + next;
      }
      dp[index][rest] = p1 > p2 ? p1 : p2;
    }
  }
  return dp[0][bag];
}

// 分治 : 分而治之 大禹治水
//  leetcode 53 最大连续子序列和

int maxSubarray(vector<int> nums, int begin, int end) {
  if (end - begin < 2) return nums[begin];

  int mid = (begin + end) >> 1;
  int leftMax = 0;
  int leftSum = 0;
  for (int i = mid - 1; i >= begin; i--) {
    leftSum += nums[i];
    leftMax = leftMax > leftSum ? leftMax : leftSum;
  }
  int rightMax = 0;
  int rightSum = 0;
  int max = leftMax + rightMax;

  int t1 = maxSubarray(nums, begin, end);
  int t2 = maxSubarray(nums, begin, end);
  int tmax = t1 > t2 ? t1 : t2;

  return max > tmax ? max : tmax;
}

void placeQueens(int n);
void place(int row);
bool isValid(int row, int col);

// 递归转非递归
// 自己维护一个栈保存变量
// 用一个容器存储相同的变量
//  回溯 DFS 深搜 能进则进，不能进能退回上一步
//  八皇后问题 51  52
// 在 8*8
// 的格子上面摆放八个皇后，使用它们不能相互攻击：任意两个皇后都不能处于同一行，同一列或者同一个斜线上，一共有多少种摆法？
// 皇后的攻击范围：皇后的对角线，它所处的同一行或同一列
//  剪枝 Pruning

// 从第 row 行开始摆放皇后
// common
int temp = 8;  // 需要更改这个来求几个皇后
vector<int> cols(temp, 0);
int ways;  // 多少种摆法
void placeQueens(int n) {
  if (n < 1) return;
  temp = n;
  place(0);
  cout << "皇后一共有" << ways << "种摆法" << endl;
}
// 数组索引是行号，数组元素是行号  eg: cols[4] = 5 第四行的皇后在第5列

void place(int row) {
  if (row == cols.size()) {
    ways++;
    return;
  }
  for (int col = 0; col < cols.size(); col++) {
    if (isValid(row, col)) {
      // 在第 row 行， 第 col 列摆放皇后
      cols[row] = col;
      place(row + 1);
      //   回溯
    }
  }
}

// 判断第 row 行 第 col 列是否可以摆放皇后
bool isValid(int row, int col) {
  for (int i = 0; i < row; i++) {
    // 第 col 列已经有皇后了
    if (cols[i] == col) return false;
    // 斜线上有皇后    利用数学公式斜率求在斜线上的
    if (row - i == abs(col - cols[i])) return false;
  }
  return true;
}

int main() {
  vector<int> w = {3, 2, 4, 7, 3};
  vector<int> v = {5, 6, 3, 19, 12};
  int bag = 11;
  //   cout << maxValue(w, v, bag) << endl;
  //   cout << dp(w, v, bag) << endl;
  placeQueens(4);
  cout << ways << endl;
}