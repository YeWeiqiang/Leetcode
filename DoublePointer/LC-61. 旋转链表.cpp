/**
 * 61. 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* p1 = head;
        ListNode* p2 = head;

        int n = 0;
        ListNode* temp = head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        k = k%n;

        while(k--)
        {
            p2 = p2->next;
        }
        if(!p2){
            return head;
        }else{
            while(p2->next != NULL){
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        p2->next = head;
        head = p1->next;
        p1->next = NULL;

        return head;
    }
};