/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  // int memo[46];
  // int climbStairs(int n) {
  //   // if (n <= 0) return 0;
  //   // if (n == 1) return 1;
  //   // if (n == 2) return 2;
  //   // if (n == 3) return 3;
  //   // return climbStairs(n - 1) + climbStairs(n - 2);
  //   for (int i = 0; i < 45; i++) {
  //     memo[i] = 0;
  //   }
  //   return dp(n);
  // }

  // int dp(int n) {
  //   if (n <= 2) return n;

  //   if (memo[n] > 0) return memo[n];

  //   memo[n] = dp(n - 1) + dp(n - 2);
  //   return memo[n];
  // }

  int climbStairs(int n) {
    if (n < 2) return 1;
    int ways = 0;
    int prev = 1;
    int sced = 1;
    int t = 0;
    for (int i = 2; i < n + 1; i++) {
      t = sced;
      sced = prev + sced;
      prev = t;
    }
    return sced;
  }
};
// @lc code=end
