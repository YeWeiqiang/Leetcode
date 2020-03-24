/**
 * 142. 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* meet = NULL;

        while(p2 != NULL)
        {
            if(p2->next != NULL && p2->next->next != NULL){
                p2 = p2->next->next;
                p1 = p1->next;
            }else{
                return NULL;
            }
            if(p1 == p2){
                meet = p2;
                break;
            }
        }
        if(p2 == NULL) return NULL;

        while(head != p2)
        {
            head = head->next;
            p2 = p2->next;
        }

        return head;
    }
};