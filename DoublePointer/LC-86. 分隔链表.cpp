/**
 * 86. 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode L1(0), L2(0);
        ListNode* p1 = &L1;
        ListNode* p2 = &L2;

        while(head)
        {
            if(head->val < x){
                p1->next = head;
                p1 = head;
            }else{
                p2->next = head;
                p2 = head;
            }
            head = head->next;
        }
        p2->next = NULL;
        p1->next = L2.next;

        return L1.next;
    }
};