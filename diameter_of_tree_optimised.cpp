#include <bits/stdc++.h>
#include "binary_tree.hpp"

using namespace std;

pair<int,int> diameter(BinaryTree<int> *root)
{
    pair<int,int> results;   //first diameter second height

    if(!root)
    {
        results.first=0;
        results.second=0;
        return results;
    }

    pair<int,int> left=diameter(root->left),right=diameter(root->right);

    int dia = max({left.first,right.first,left.second+right.second});
    int sum = max(left.second,right.second)+1;
    return pair<int,int>(dia,height);
}

int main()
{
    BinaryTree<int> *root = sample_binary_tree();
    cout<<diameter(root).first;
    return 0;
}
