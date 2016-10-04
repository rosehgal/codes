#include <bits/stdc++.h>
using namespace std;


struct tree{
    int val;
    int leftCount;
    tree *left,*right;
};


tree *get_node(int val)
{
    tree*ptr = new tree;
    ptr->val=val;
    ptr->left=ptr->right=NULL;
    ptr->leftCount=0;
    return ptr;
}

void insertmytree(tree* &root,int val)
{
    if(!root)
    {
        root=get_node(val);
        return ;
    }
    else if(val<root->val && root->left)
    {
        root->leftCount++;
        insertmytree(root->left,val);
    }
    else if(val<root->val && !root->left)
    {
        root->left = get_node(val);
        root->leftCount++;
    }
    else if(val>root->val && root->right)
        insertmytree(root->right,val);
    else if(root->val<val && !root->right)
        root->right = get_node(val);
}

void inorder(tree *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<"("<<root->val<<","<<root->leftCount<<")\t";
    inorder(root->right);
}

int kth_element(tree*root,int k)
{
    if(k==root->leftCount)
        return root->val;
    else if(k<root->leftCount)
        return kth_element(root->left,k);
    else
        return kth_element(root->right,k-root->leftCount-1);
}


int main()
{
    int nodes;
    ifstream in("input_tree.dat",ios::in);
    in>>nodes;
    tree*root=NULL;
    while(nodes--)
    {
        int n;
        in>>n;
        insertmytree(root,n);
    }
    inorder(root);
    int k;
    cin>>k;
    cout<<kth_element(root,k);
    return 0;
}
