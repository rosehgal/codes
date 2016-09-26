#include <bits/stdc++.h>
#include "binary_tree.hpp"

using namespace std;

pair<int,int> max_sum_path(BinaryTree<int> *root)
{
    pair<int,int> results;   //first total sum second max path sum

    if(!root)
    {
        results.first=0;
        results.second=0;
        return results;
    }

    pair<int,int> left=max_sum_path(root->left),right=max_sum_path(root->right);

    int dia = max({left.first,right.first,left.second+right.second});
    int sum = max(left.second,right.second)+root->val;
    return pair<int,int>(dia,sum);
}

int main()
{
    BinaryTree<int> *root = sample_binary_tree();
    cout<<max_sum_path(root).first;
    return 0;
}
