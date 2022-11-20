/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr && list2 == nullptr) return nullptr;
    if (list1 == nullptr && list2 != nullptr) return list2;
    if (list2 == nullptr && list1 != nullptr) return list1;
    //   平常最好不好直接操作传递进行的头结点，应该用一个变量保存起来，再进行操作
    // 返回链表的头结点
    ListNode* virtualhead = new ListNode(-1);
    ListNode* head = virtualhead;
    while (list1 != nullptr && list2 != nullptr) {
      // l1 > l2
      if (list1->val > list2->val) {
        head->next = list2;
        list2 = list2->next;
      } else {  // <
        head->next = list1;
        list1 = list1->next;
      }
      head = head->next;
    }
    // 判断长的那个链表还有元素
    if (list1 != nullptr) {
      head->next = list1;
    }
    if (list2 != nullptr) {
      head->next = list2;
    }

    // head->next = (list1==nullptr)?list2:list1;

    return virtualhead->next;
  }

  //  解决思路和上面那个一样
  // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
  // {
  //     ListNode* list3 = new ListNode;
  //     ListNode* p3 = list3;
  //     while(list1 && list2)
  //     {
  //         if(list1->val < list2->val)
  //         {
  //             list3->next = new ListNode;
  //             list3->next->val = list1->val;
  //             list1 = list1->next;
  //             list3 = list3->next;
  //         }
  //         else
  //         {
  //             list3->next = new ListNode;
  //             list3->next->val = list2->val;
  //             list2 = list2->next;
  //             list3 = list3->next;
  //         }
  //     }
  //     list3->next = (list1 == nullptr)? list2 : list1;
  //      return p3->next;
  // }

  // 解法思路二： 在传递进行来的链表上操作，不开辟一个新头
};
// @lc code=end
