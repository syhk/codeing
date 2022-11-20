/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */
#include "vector"
using std::vector;
// @lc code=start
class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> vec1, vec2(nums.size() + 1, 0);
    int temp = 0;
    // for (int i : nums) {
    //   if (vec2.at(i) == 0)
    //     vec2.at(i) = i;
    //   else
    //     vec1.push_back(i);
    // }
    for (int i = 0; i < nums.size(); i++) {
      while (nums.at(i) != i) {
        if (nums.at(i) >= nums.size()) break;
        if (nums.at(i) == nums.at(nums.at(i))) {
          vec1.push_back(nums.at(i));
          break;
        }
        // swap
        temp = nums.at(i);
        nums.at(i) = nums.at(temp);
        nums.at(temp) = temp;
      }
    }
    return vec1;
  }
};
// @lc code=end
