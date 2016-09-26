#include <iostream>
#include "binary_tree.hpp"

using namespace std;

int main()
{
    BinaryTree<int> *root = sample_binary_tree();
    cout<<diameter(root);
    return 0;
}
