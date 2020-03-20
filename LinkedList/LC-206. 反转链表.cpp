/**
 * 206. 反转链表 == 面试题24. 反转链表
 */

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
    ListNode* reverseList(ListNode* head) {
        ListNode p(0);
        ListNode* temp;
        while(head != NULL)
        {
            temp = head->next;
            head->next = p.next;
            p.next = head;
            head = temp;
        }

        return p.next;
    }
};