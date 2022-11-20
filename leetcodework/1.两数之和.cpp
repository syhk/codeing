#include "iostream"
#include "vector"

using std::vector;

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

using std::vector;
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> vec;
    if (nums.size() == 0) return vec;
    if (nums.size() == 1) return nums;
    for (int i1 = 0; i1 < nums.size(); i1++) {
      for (int i = i1 + 1; i < nums.size(); i++) {
        if (nums[i1] + nums[i] == target) {
          vec.push_back(i1);
          vec.push_back(i);
          return vec;
        }
      }
    }
    return vec;
  }
};
// @lc code=end
