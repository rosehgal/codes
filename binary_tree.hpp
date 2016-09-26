#include <iostream>
using namespace std;

template<class type>
struct BinaryTree
 {
     type val;
     BinaryTree *left,*right;
 };


template<typename type>
BinaryTree<type>* get_node(type val)
{
    BinaryTree<type> *temp = new BinaryTree<type>;
    temp->val=val;
    temp->left=temp->right=NULL;
}



//inserts in an empty node!
template<typename type>
void insert(BinaryTree<type> * &root,type data)
{
    if(!root)
        root=get_node(data);
    else
        return ;
}

template<typename type>
void inorder(BinaryTree<type> *root)
{
    if(!root)
        return ;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}


BinaryTree<int> * sample_binary_tree()
{
    BinaryTree<int> *root = NULL;
    insert(root,10);
    insert(root->left,2);
    insert(root->right,4);
    insert(root->left->left,3);
    insert(root->left->right,1);
    insert(root->left->right->left,3);
    insert(root->left->right->left->left,2);
    insert(root->left->right->left->right,4);
    insert(root->right,4);
    insert(root->right->left,5);
    insert(root->right->right,7);
    insert(root->right->left->left,1);
    return root;
}

// template<typename type>
// void insert_arr_to_tree(BinaryTree* &root,vector<type> arr)
// {
//     queue<type> dataq;
//     for(auto &a:arr)
//         dataq.push(a);
//
//     queue<pair<BinaryTree*,BinaryTree*>> treeq;
//     treeq.push(pair<BinaryTree*,BinaryTree*>(root,NULL));
//
//     while(!dataq.empty())
//     {
//         pair<BinaryTree*,BinaryTree*>  node_pair = treeq.front();
//
//         type data =  dataq.front();
//
//         dataq.pop();
//         treeq.pop();
//
//         pair<BinaryTree*,BinaryTree*> node_to_insert;
//
//         node_to_insert.first=node_pair.first;
//         node_to_insert.second=node_pair.first->left;
//
//         insert(node_pair,data);
//         treeq.push(node_to_insert);
//         node_to_insert.second=node_pair.first->right;
//         treeq.push(node_to_insert);
//     }
// }
