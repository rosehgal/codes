#include<iostream>
using namespace std;

template<typename type>
struct node{
      type value;
      node<type> *next;
};

template<typename type>
struct dllnode{
      type value;
      dllnode<type> *prev,*next;
};


template<typename type>
node<type>* getnodell(type data)
{
      node<type> *n = new node<type>;
      n->value=data;
      n->next=NULL;
      return n;
}

template<typename type>
dllnode<type>* getnodedll(type data)
{
      dllnode<type> *n = new dllnode<type>;
      n->value=data;
      n->next=NULL;
      n->prev=NULL;
      return n;
}

template<typename type>
void insert(node<type>* &head,type data)
{
      if(!head)
            head=getnodell(data);
      else{
            node<type> *ptr=head;
            while(ptr->next)
                  ptr=ptr->next;
            ptr->next=getnodell(data);
      }
}

template<typename type>
void insert(dllnode<type>* &head,type data)
{
      if(!head)
            head=getnodedll(data);
      else{
            dllnode<type> *ptr=head;
            while(ptr->next)
                  ptr=ptr->next;
            ptr->next=getnodedll(data);
            ptr->next->prev=ptr;
      }
}

template<typename type> void printlist(node<type> *head)
{
      while(head)
      {
            cout<<head->value<<" ";
            head=head->next;
      }
}


template<typename type> void printlist(dllnode<type> *head)
{
      while(head)
      {
            cout<<head->value<<" ";
            head=head->next;
      }
}

template<typename type> void printlistrev(dllnode<type> *head)
{
      while(head)
      {
            cout<<head->value<<" ";
            head=head->prev;
      }
}
