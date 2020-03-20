/**
 * 141. 环形链表
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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        if(head == NULL) return false;
        while(fast != NULL)
        {
            if(fast->next != NULL && fast->next->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
            }else{
                return false;
            }
            if(fast == slow) return true;

        }

        return false;
    }
};