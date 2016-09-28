#include <bits/stdc++.h>
#include "binary_tree.hpp"
using namespace std;

int how_many_subsequence(BinaryTree<char> *root,string str,int i)
{
    static int count = 0;
    if(root && !root->left && !root->right && i==str.size())
    {
        count++;
        return count;
    }

    if(i==str.size() || root->val!=str[i])
    {
        if(root->left)
            how_many_subsequence(root->left,str,i);
        if(root->right)
            how_many_subsequence(root->right,str,i);
    }
    else if(root->val == str[i])
    {
        if(!root->left && !root->right)
            count++;
        if(root->left)
            how_many_subsequence(root->left,str,i+1);
        if(root->right)
            how_many_subsequence(root->right,str,i+1);
    }
    return count;
}


int main()
{
    string str;
    cin>>str;

    BinaryTree<char> *root = sample_binary_tree_char();

    cout<<how_many_subsequence(root,str,0);
    return 0;
}
