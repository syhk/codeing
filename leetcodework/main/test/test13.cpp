#include "iostream"
#include "string"
#include "vector"
using namespace std;
class Solution {
 public:
  bool isAnagram(string s, string t) {
    vector<int> result(25, 0);
    for (int i = 0; i < s.length(); i++) {
      result[s[i] - 'a'] += 1;
      result[t[i] - 'a'] -= 1;
    }
    for (auto i : result) {
      if (i != 0) return false;
    }
    return true;
  }
};
void get(int n) {
  int temp = 0;
  while (n > 0) {
    temp = n % 10;
    n /= 10;
    cout << temp << endl;
  }
}
int main() {
  Solution S;
  // string s = "anagram";
  // string t = "nagarax";
  // cout << boolalpha;
  // cout << S.isAnagram(s, t);
  // int n = 8952;
  // get(n);
  string num = "457868";
  int dig = static_cast<int>(num[1]);
  cout << dig;
  return 0;
}