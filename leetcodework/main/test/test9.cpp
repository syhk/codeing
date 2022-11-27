/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */
#include "algorithm"
#include "iostream"
#include "numeric"
#include "vector"

using namespace std;
// @lc code=start
class Solution {
 public:
  // 答案不会比平均数低(想想) && 同时答案应该比 max(weights) 大
  int shipWithinDays(vector<int>& weights, int days) {
    // 确定二分查找左右边界
    int left = *max_element(weights.begin(), weights.end()),
        right = accumulate(weights.begin(), weights.end(), 0);
    while (left < right) {
      int mid = (left + right) / 2;
      // need 为需要运送的天数
      // cur 为当前这一天已经运送的包裹重量之和
      int need = 1, cur = 0;
      for (int weight : weights) {
        if (cur + weight > mid) {
          ++need;
          cur = 0;
        }
        cur += weight;
      }
      if (need <= days) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
// @lc code=end
// my  code
int main() {
  Solution s;
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  cout << s.shipWithinDays(arr, 5);
  // cout << accumulate(arr.begin(), arr.end(), 2);
  return 0;
}