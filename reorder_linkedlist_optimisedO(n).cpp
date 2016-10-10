
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

void reorderList(ListNode* head) {
    if(!head)
        return;
    ListNode *newlist=NULL,*nptr;
    ListNode *ptr=head;
    int len=0;
    nptr=newlist;
    while(ptr){
        len++;
        if(!newlist){
            newlist=new ListNode(ptr->val);
            nptr=newlist;
        }
        else{
            nptr->next=new ListNode(ptr->val);
            nptr=nptr->next;
        }
        ptr=ptr->next;
    }
    nptr=newlist;
    ListNode *nnptr,*cptr=NULL;
    while(nptr){
        nnptr=nptr->next;
        nptr->next=cptr;
        cptr=nptr;
        nptr=nnptr;
    }
    newlist=cptr;
    ptr=head;
    ListNode *nlptr;
    while(len>=2)
    {
        len=len-2;
        nptr=ptr->next;
        ptr->next=newlist;
        nlptr=newlist->next;
        if(len==0)
            newlist->next=NULL;
        else if(len==1){
            newlist->next=nptr;
            nptr->next=NULL;
        }
        else
            newlist->next=nptr;
        newlist=nlptr;
        ptr=nptr;

    }
}
