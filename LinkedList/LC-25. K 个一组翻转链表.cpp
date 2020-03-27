/**
 * 25. K 个一组翻转链表
 */


ListNode* p;
ListNode* temp;
while(head)
{
    temp = head->next;
    head->next = p->next;
    p->next = head;
    head = temp;

}