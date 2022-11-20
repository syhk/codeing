/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    // 判别错误输入
    if (head == nullptr) return false;
    if (head->next == nullptr) return false;
    // 利用快慢指针思路
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      // 慢指针走一步，快指针走两步
      slow = slow->next;
      fast = fast->next->next;
      // 两指针相遇有环
      if (slow == fast) return true;
    }
    // 无环
    return false;
  }

  // 缺点：辅助空间占用太大
  //   bool hasCycle(ListNode *head) {
  //     // 判别错误输入
  //     if (head == nullptr) return false;
  //     if (head->next == nullptr) return false;
  //         std::set<ListNode*> NSet;
  //         bool falg=false;
  //         while (head!= nullptr) {
  //             if( !(NSet.insert(head).second)) return true;
  //             head = head->next;
  //         }
  //         return false;
  //   }

  //    bool hasCycle(ListNode *head) {
  //     ListNode *s, *f;
  //         s = f = head;
  //         while(f && f->next){
  //             s = s->next;
  //             f = f->next->next;
  //             if(s == f){return true;}
  //         }

  //         return false;
  //    }
};
// @lc code=end
