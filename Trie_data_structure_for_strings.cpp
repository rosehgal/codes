#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *next[26];
    bool is_leaf;
    TrieNode(){
        for(int i=0;i<26;++i)
            this->next[i]=NULL;
        this->is_leaf=false;
    }
};

class Trie {
public:
    Trie(){
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *ptr=root;
        for(char c:word){
            if(ptr->next[c-'a']==NULL){
                ptr->next[c-'a']=new TrieNode();
                ptr=ptr->next[c-'a'];
            }
            else
                ptr=ptr->next[c-'a'];
        }
        ptr->is_leaf=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *ptr=root;
        for(char c:word){
            if(ptr->next[c-'a']==NULL)
                return false;
            else
                ptr=ptr->next[c-'a'];
        }
        return ptr->is_leaf==true;

    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *ptr=root;
        for(char c:prefix){
            if(ptr->next[c-'a']==NULL)
                return false;
            else
                ptr=ptr->next[c-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


int main(){
    Trie trie;
    trie.insert("rohit");
    cout<<trie.startsWith("o");
    return 0;
}
