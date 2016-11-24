#include <cmath>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
    int val;
    node *prev,*next;
};

class DoublyLinkedList{
        node *root,*last;
    public:
        int size;
        node *getNode(int val){
            node * ptr = new node;
            ptr->val=val;
            ptr->prev=ptr->next=NULL;
            return ptr;
        }
        DoublyLinkedList(){
            root=NULL;
            size=0;
        }
        node *insert(int val){
            node *n=getNode(val);
            if(!root)
                last=root=n;
            else{
                n->next=root;
                root->prev=n;
                root=n;
            }
            size++;
            return n;
        }
        void remove(node *ptr){
            if(ptr==last){
                remove();
                size--;
                return;
            }
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            size--;
        }
        void remove(){
            if(last==root){
                root=NULL;
                size--;
                return;
            }
            last=last->prev;
            last->next=NULL;
            size--;
        }
        void print(){
            node *ptr=root;
            while(ptr){
                cout<<ptr->val<<" ";
                ptr=ptr->next;
            }
        }
        node* lastptr(){
            return last;
        }
};

class LRUcache{
    DoublyLinkedList *cache;
    unordered_map<int,node*> hash;
    int cacheSize;
    public:
    LRUcache(int size){
        cacheSize=size;
        cache=new DoublyLinkedList;
    }
    bool inCache(int pageNum){
        if(hash.count(pageNum)<1){
            if(cache->size<cacheSize){
                node * ptr = cache->insert(pageNum);
                hash[pageNum]=ptr;
            }
            else{
                hash.erase(cache->lastptr()->val);
                cache->remove();
                hash[pageNum]=cache->insert(pageNum);
            }
            return false;
        }
        else{
            node *ptr=hash[pageNum];
            hash.erase(pageNum);
            node *newptr = cache->insert(pageNum);
            hash[pageNum]=newptr;
            cache->remove(ptr);
        }
        return true;
    }
    void printCache(){
        cache->print();
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int pagecount,cachesize;
    cin>>pagecount>>cachesize;
    vector<int> pages(pagecount);
    LRUcache cache(cachesize);
    for(int i=0;i<pagecount;++i)cin>>pages[i];
    int pageFaults=0;
    for(int i=0;i<pages.size();++i)if(!cache.inCache(pages[i]))pageFaults++;
    cout<<pageFaults<<endl;
    cache.printCache();
    return 0;
}

