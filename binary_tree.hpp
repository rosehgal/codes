#include <vector>

template<class type>
struct BinaryTree
 {
     type val;
     BinaryTree *left,*right;
 };


template<typename type>
BinaryTree* get_node(type val)
{
    BinaryTree *temp = new BinaryTree;
    temp->val=val;
    temp->left=temp->right=NULL;
}

void insert(BinaryTree* &root,vector<int> arr)
{
    if(!root)
}
