#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode*left,*right;
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root)return NULL;
    if(root==p)return p;
    else if(root==q)return q;

    TreeNode *left=lowestCommonAncestor(root->left,p,q),*right=lowestCommonAncestor(root->right,p,q);
    if((left==p&&right==q) || (left==q&&right==p)) return root;
    else if(!left&&right) return right;
    else if(left&&!right) return left;
    return NULL;
}

int main(){
    
}
