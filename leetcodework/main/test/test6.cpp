#include <string>

#include "iostream"
#include "stack"
#include "string"

using namespace std;
// @lc code=start
class Solution {
 public:
  //   string reverseStr(string s, int k) {
  //     stack<char> cstack;
  //     if (s.size() == 0 || s.size() == 0) return s;
  //     for (int i = 0; i < k; i++) {
  //       // 先入栈需要反转的字符串
  //       cstack.push(s[i]);
  //     }
  //     int i = 0;
  //     // 再出线替换字符
  //     while (!cstack.empty()) {
  //       s[i++] = cstack.top();
  //       cstack.pop();
  //     }
  //     return s;
  //   }
  string reverseStr(string& s, int k) {
    int n = s.size();
    if (n == 0 || n == 1) return s;
    char temp = 's';
    for (int i = 0; i < n; i++, k--) {
      if (k < 0) return s;
      //   cout << temp << '\t';
      temp = s[i];
      //   cout << "i：" << s[i] << '\t';
      s[i] = s[k];
      //   cout << "k：" << s[k] << '\t';
      s[k] = temp;
    }
    cout << "s=" << s << endl;
    return s;
  }
};

int main() {
  Solution s;
  string s1 = "abcdefg";
  //   cout << s.reverseStr(s1, 3);
  s1[0] = 's';
  cout << s1;
}