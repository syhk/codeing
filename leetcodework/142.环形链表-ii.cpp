/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
  //  思路： 和简单环形链表一样，利用 set
  //  集合的元素唯一性，当无法插入时，无法插入的那个元素就是环开始的第一个结点
  //   ListNode *detectCycle(ListNode *head) {
  //     if (head == nullptr) return nullptr;
  //     if (head->next == nullptr) return nullptr;
  //     set<ListNode *> SNode;
  //     while (head != nullptr) {
  //       if (!SNode.insert(head).second) {
  //         return head;
  //       }
  //       head = head->next;
  //     }
  //     return nullptr;
  //   }

  // 解法二
  // 思路： 使用快慢指针解法: 让 slow pointer  走一步， fast pointer 走两步 ,
  // 记录 fast 所走的长度
  ListNode* detectCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while (true) {
      // 两指针相遇
      if (slow == fast) {
        break;
      }
      fast = fast->next->next;
      slow = slow->next;
    }
    fast = head;
    while (slow != fast) {
      slow = slow.next;
      fast = fast.next;
    }
    return fast;
  }
};
// @lc code=end
