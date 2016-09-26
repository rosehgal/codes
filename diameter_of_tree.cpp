#include <iostream>
#include "binary_tree.hpp"

using namespace std;

template<typename type>
int height(BinaryTree<type> *root)
{
    if(!root)
        return 0;
    else
        return max(height(root->left),height(root->right))+1;
}

template<typename type>
int diameter(BinaryTree<type>* root)
{
    if(!root)
        return 0;
    int height_left=height(root->left);
    int height_right=height(root->right);

    return max(max(diameter(root->left),diameter(root->right)),height(root->left)+height(root->right));
}

int main()
{
    BinaryTree<int> *root = sample_binary_tree();
    //inorder(root);
    cout<<diameter(root);
    return 0;
}
