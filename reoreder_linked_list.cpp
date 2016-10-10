
/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
*/

#include <bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head)
{
    if(!head || !head->next || !head->next->next)
        return;
    ListNode *ptr = head;
    while(ptr && ptr->next && ptr->next->next)
        ptr=ptr->next;
    ListNode *nptr=head->next;
    ptr->next->next=head->next;
    head->next=ptr->next;
    ptr->next=NULL;
    reorderList(nptr);
}
