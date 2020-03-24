/**
 * 19. 删除链表的倒数第N个节点   面试题22. 链表中倒数第k个节点
 *
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = head;

        while(n--)
        {
            p2 = p2->next;
        }
        if(!p2){
            head = p1->next;  //避开n为链表长度的情况
        }else{
            p2 = p2->next;
            while(p2 != NULL)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            p1->next = p1->next->next;
        }

        return head;
    }
};


/**
 * 面试题22. 链表中倒数第k个节点
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p1 = head;
        ListNode* p2 = head;

        while(k--)
        {
            p2 = p2->next;
        }
        if(!p2){
            return p1;
        }else{
            p2 = p2->next;
            while(p2 != NULL){
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        return p1->next;
    }
};