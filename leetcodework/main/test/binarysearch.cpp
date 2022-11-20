#include "iostream"
#include "vector"
using namespace std;

int BS(vector<int> &vec, int target);
int main() {
  vector<int> vec = {2, 14, 56, 78, 123, 567, 1233};
  cout << BS(vec, 1233);
}

int BS(vector<int> &vec, int target) {
  int left = 0, right = vec.size() - 1;
  while (left <= right) {
    int mid = left + ((right - left) >> 1);  // 这里需要括号，因为优先级的关系，
    if (vec[mid] == target)
      return mid;
    else if (vec[mid] < target)
      left = mid + 1;
    // >
    else
      right = mid - 1;
  }
  return -1;
}
