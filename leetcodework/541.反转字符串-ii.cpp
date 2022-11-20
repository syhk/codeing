/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include "iostream"
#include "stack"
#include "string"

using namespace std;
// @lc code=start
class Solution {
 public:
  string reverseStr(string s, int k) {
    stack<char> cstack;
    if (s.size() == 0 || s.size() == 0) return s;
    for (int i = 0; i < k; i++) {
      // 先入栈需要反转的字符串
      cstack.push(s[i]);
    }

    int i = 0;
    // 再出线替换字符
    while (!cstack.empty()) {
      s[i++] = cstack.top();
      cstack.pop();
    }

    return s;
  }
};

int main() {
  Solution s;
  cout << s.reverseStr("abcdefg", 2);
}
// @lc code=end
