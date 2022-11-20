#include "iostream"
#include "vector"
using std::cout;
using std::endl;
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
  int findDup(vector<int>& nums) {
    int start = 1;
    int end = nums.size();
    while (end >= start) {
      int middle = ((end - start) >> 1) + start;
      int count = this->countRange(nums, end, start, end);
      if (end == start) {
        if (count > 1)
          return start;
        else
          break;
      }
      if (count > (middle - start + 1))
        end = middle;
      else
        start = middle + 1;
    }
    return -1;
  }
 private:
  int countRange(const vector<int> nums, int len, int start, int end) {
    if (nums.empty()) return 0;
    int count = 0;
    for (int i = 0; i < len; i++) {
      if (nums[i] >= start && nums[i] <= end) ++count;
    }
    return count;
  }
};
int main() {
  vector<int> vec = {4, 3, 2, 7, 8, 2, 3, 1};
  Solution s;
  // vector<int> v = s.findDuplicates(vec);
  cout << "==================输出结果为：" << endl;
  // for (int i : v) {
  //   cout << i << '\t';
  // }
  cout << s.findDup(vec);
  return 0;
}
