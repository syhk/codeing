/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>

#include "iostream"

using std::cout;
using std::endl;
using std::string;
// @lc code=start
class Solution {
 public:
  string answer = "";
  string longestPalindrome(string s) {
    cout << "fsdfds" << endl;
    if (s.empty()) return "";
    if (s.size() == 1) return "";
    string temp = "";
    for (auto a : s) {
      temp += a;
      cout << "本次传递的字符串为： " << temp << endl;
      finds(temp);
    }
    return answer;
  }

  // 判断 s 是否是回文串
  void finds(string s) {
    int p1 = 0, p2 = s.size();
    while (p1 < p2) {
      p1++;
      p2--;
      if (s[p1] != s[p2]) {
        return;
      }
    }
    // 是否回文串
    answer = s;
  }
};

int main() {
  Solution s;
  string str = "babad";
  s.longestPalindrome(str);
  cout << s.answer << endl;

  return 0;
}
// @lc code=end
