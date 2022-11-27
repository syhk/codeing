#include "iostream"
#include "vector"
using namespace std;
int search2(vector<int>& nums, int target) {
  int N = nums.size();
  if (N == 1) return nums[0] == target ? 0 : -1;
  int left = 0, right = N - 1, mid = (right - left) >> 1;
  while (left <= right) {
    if (nums[mid] > target) {
      right = mid - 1;
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {
      return mid;
    }
    mid = left + ((right - left) >> 1);
  }
  return -1;
}
int search(vector<int>& nums, int target) {
  int N = nums.size();
  if (N == 0) return 0;
  if (N == 1) return nums[0] == target ? 1 : 0;
  if (nums[0] == nums[N - 1] && nums[0] == target) return N;
  int left = 0, right = N - 1, mid = (left + right) >> 1;
  int ans = 0;
  while (left <= right) {
    if (nums[mid] > target) {
      right = mid - 1;
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {  // find target
      ans++;
      int i = mid - 1, j = mid + 1;
      while (i >= left || j <= right) {
        if (i >= 0 && nums[i] == target) {
          ans++;
        }
        if (j < N && nums[j] == target) {
          ans++;
        }
        i--;
        j++;
      }
      return ans;
    }
    mid = (left + right) >> 1;
  }
  return 0;
}
// ==================================================================================
vector<int> ans;
int N = 0;
int search3(vector<int>& nums, int target) {
  int left = 0, right = N - 1, mid = (left + right) >> 1;
  //   二分需要返回第一个 target 出现的地方
  bool flag = false;
  while (left <= right) {
    if (nums[mid] >= target) {
      if (nums[mid] == target) flag = true;
      right = mid - 1;
    } else if (nums[mid] < target) {
      left = mid + 1;
    }
    mid = (left + right) >> 1;
  }
  return flag ? right + 1 : -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
  N = nums.size();
  if (N == 0) return {-1, -1};
  if (N == 1 && nums[0] == target) return {0, 0};
  if (nums[0] == nums[N - 1] && N != 1 && nums[0] == target) return {0, N - 1};
  int firstfind = search3(nums, target);  // target 第一次出现的位置
  // 返回 -1 代表没有
  if (firstfind == -1) {
    return {-1, -1};
  }

  ans.push_back(firstfind);
  for (; firstfind < N; firstfind++) {
    if (nums[firstfind] != target) break;
  }
  // 停留在最后一个位置
  ans.push_back(firstfind - 1);
  if (ans.size() == 1) {
    ans.push_back(ans[0]);
  }
  return ans;
}
int main() {
  vector<int> arr = {-1, 0, 3, 5, 9, 12};
  vector<int> arr1 = {1};
  // int tar = search(arr1, 5);
  // cout << tar;
  vector<int> an = searchRange(arr1, 0);
  for (auto i : an) {
    cout << i << '\t';
  }
  // cout << search(arr1, 0);

  return 0;
}