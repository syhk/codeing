/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  //  DFS
  //   bool isSameTree(TreeNode* p, TreeNode* q) {
  //     // 两棵树都为空也是相同的
  //     if (p == nullptr && q == nullptr) return true;
  //     if (p == nullptr || q == nullptr || p->val != q->val) return false;
  //     // DFS
  //     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  //   }

  // BFS
  bool isSameTree(TreeNode* p, TreeNode* q) {
    // 两棵树都为空也是相同的
    if (p == nullptr && q == nullptr)
      return true;
    else if (p == nullptr || q == nullptr || p->val != q->val)
      return false;
    // BFS
    std::queue<TreeNode*> queue1, queue2;
    queue1.push(p);
    queue2.push(q);
    while (!queue1.empty() && !queue2.empty()) {
      auto n1 = queue1.front();
      queue1.pop();
      auto n2 = queue2.front();
      queue2.pop();
      if (n1->val != n2->val) return false;

      auto l1 = n1->left, r1 = n1->right, l2 = n2->left, r2 = n2->right;
      //   使用异或，我想不到，感觉比较巧妙
      if (l1 == nullptr ^ l2 == nullptr) return false;
      if (r1 == nullptr ^ r2 == nullptr) return false;

      if (l1 != nullptr) queue1.push(l1);
      if (r1 != nullptr) queue1.push(r1);

      if (l2 != nullptr) queue2.push(l2);
      if (r2 != nullptr) queue2.push(r2);
    }
    return queue1.empty() && queue2.empty();
  }
};
// @lc code=end