/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    // 先用 n 个节点指针把 head 保存下来
    std::vector<ListNode*> heads(lists.size());
    ListNode* ansHead = new ListNode(0);

    while (isNULL(heads)) {
      for (int i = 0; i < heads.size(); i++) {
        heads[i] = lists[i];
        // 将所有 heads 里面的节点都为空了才结束
        while (isNULL(heads)) {
          // 把节点连接到 ansHead 链表上
          ansHead->next = head[i];
          // 下走一步
          heads[i] = heads[i]->next;
          break;
        }
      }
    }
    return ansHead->next;
  }

  //   传递进来的 vector 判断里面的元素是否全为空
  bool isNULL(vector<ListNode*>& vec) {
    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] != nullptr) return false;
    }
    return true;
  }
};
// @lc code=end
