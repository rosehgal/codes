#include <bits/stdc++.h>
#include "binary_tree.hpp"


vector<int> rightSideView(BinaryTree<int>* root) {
    if(!root)return vector<int>{};
    queue<pair<BinaryTree<int>*,int>> level;
    vector<int> result;
    level.push({root,0});
    while(!level.empty()){
        pair<BinaryTree<int>*,int> curr=level.front();level.pop();
        if(result.size()<curr.second+1)result.push_back(curr.first->val);
        else result[curr.second]=curr.first->val;
        if(curr.first->left)level.push({curr.first->left,curr.second+1});
        if(curr.first->right)level.push({curr.first->right,curr.second+1});
    }
    return result;
}

int main(){
    BinaryTree<int> *root= sample_binary_tree();
    for(auto v:rightSideView(root))
        cout<<v<<" ";
    return 0;
}
