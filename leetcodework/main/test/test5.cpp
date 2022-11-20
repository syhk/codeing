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
    if (s.empty()) return "";
    if (s.size() == 1) return "";
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
      for (int j = i + 1; j < s.size(); j++) {
        temp += s[i] + s[j];
        cout << "input fins: = " << temp << endl;
        finds(temp);
      }
      temp = "";
    }
    for (auto a : s) {
      temp += a;

      finds(temp);
    }
    return answer;
  }

  // 判断 s 是否是回文串
  void finds(string s) {
    int p1 = 0, p2 = s.size() - 1;
    while (p1 < p2) {
      if (s[p1] != s[p2]) {
        return;
      }
      p1++;
      p2--;
    }
    // 是否回文串
    answer = s;
    cout << "finds： " << s << endl;
  }
};

int main() {
  Solution s;
  string str = "cbbd";
  s.longestPalindrome(str);
  cout << s.answer << endl;

  return 0;
}