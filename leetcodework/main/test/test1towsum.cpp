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

    for (auto i1 : nums) {
      for (int i = 1; i < nums.size(); i++) {
        if (i1 + nums[i] == target) {
          vec.push_back(i - 1);
          vec.push_back(i);
          break;
        }
      }
    }
    return vec;
  }
};
// @lc code=end
int main() {
  Solution s;
  vector<int> vec = {3, 2, 4};
  vector<int> v = s.twoSum(vec, 6);
  for (int i : v) {
    std::cout << i << '\t';
  }
}