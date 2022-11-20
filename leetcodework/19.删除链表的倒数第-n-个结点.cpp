/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
  // ListNode* removeNthFromEnd(ListNode* head, int n) {
  //     if(head==nullptr || n <= 0) return nullptr;
  //     if(n==1 && head->next == nullptr) return head=nullptr;
  //     ListNode* dummy = new ListNode(0,head);
  //     // 解题思路：利用栈,把所有链表元素入栈，在 top
  //     出栈就可以知道要删除的是哪个结点
  //    stack<ListNode*> stk;
  //     ListNode* p = dummy;
  //     while(p)
  //     {
  //         stk.push(p);// 入栈
  //         p=p->next;
  //     }
  //     for(int i = 0; i < n ; i ++)
  //     {
  //        stk.pop(); // 出栈
  //     }
  //   ListNode*  p1 = stk.top();
  //     p1->next = p1->next->next;
  //    ListNode* ans =dummy->next;
  //     delete dummy;
  //     return ans;
  // }

  // 思路二：使用双指针法

  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr || n <= 0) return nullptr;
    if (n == 1 && head->next == nullptr) return head = nullptr;
    // 解题思路：双指针 p1 p2 : p2 先走当，p2和 p1 两个之间相差的元素为 n
    // 时，就双指针一起走,当 p2 走到结尾时， p1 后面那个元素就是需要删除的元素
    ListNode* virhead = new ListNode(0, head);
    ListNode* p1 = virhead;
    ListNode* p2 = virhead->next;

    for (int i = 0; i < n; i++) {
      p2 = p2->next;
    }

    while (p2 != nullptr) {
      p1 = p1->next;
      p2 = p2->next;
    }
    p1->next = p1->next->next;
    ListNode* ans = virhead->next;
    return ans;
  }
};
// @lc code=end
