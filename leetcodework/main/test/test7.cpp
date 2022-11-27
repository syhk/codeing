#include "iostream"
using namespace std;
// #include <bits/stdc++.h>
#include "unordered_map"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  unordered_map<int, int> map;
  //   order 顺序
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int N = preorder.size();
    if (N == 0) return nullptr;
    for (int i = 0; i < inorder.size(); i++) map.insert({inorder[i], i});
    return buildchildTree(preorder, 0, preorder.size() - 1, inorder, 0,
                          inorder.size() - 1);
  }
  TreeNode* buildchildTree(const vector<int>& preorder, int l1, int r1,
                           const vector<int>& inorder, int l2, int r2) {
    if (l1 > r1 && l2 > r2) return nullptr;
    TreeNode* root = new TreeNode(preorder[0]);  // 根节点
    // 获取数组中元素的下标
    int i = map.find(preorder[l1])->second;
    root->left =
        buildchildTree(preorder, l1 + 1, l1 + (i - l2), inorder, l2, i - 1);
    root->right =
        buildchildTree(preorder, l1 + (i - l2) + 1, r1, inorder, i + 1, r2);
    return root;
  }
};
int main() {}
