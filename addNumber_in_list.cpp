/**
 * Definition for singly-linked list.
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head=NULL,*ptr;
    ptr=head;
    int carry=0;

    while(l1 || l2)
    {
        int result = (l1?l1->val:0)+(l2?l2->val:0)+carry;
        carry = result/10;
        if(!head)
        {
            head=new ListNode(result%10);
            ptr=head;
        }
        else
        {
            ptr->next=new ListNode(result%10);
            ptr=ptr->next;
        }
        if(l1)
            l1=l1->next;
        if(l2)
            l2=l2->next;
    }
    if(carry)
        ptr->next=new ListNode(carry);
    return head;
}
