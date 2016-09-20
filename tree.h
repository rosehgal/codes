#include <iostream>
using namespace std;

template<typename type>
struct treenode{
      type value;
      treenode<type> *left,*right,*parent;
};


template<typename type>
void inorder(treenode<type> *& root)
{
      if(!root)
            return;
      inorder(root->left);
      cout<<root->value<<" ";
      inorder(root->right);
}

template<typename type>
void preorder(treenode<type> * & root)
{
      if(!root)
            return;
      cout<<root->value<<" ";
      preorder(root->left);
      preorder(root->right);
}

template<typename type>
void postorder(treenode<type> * &root)
{
      if(!root)
            return;
      postorder(root->left);
      postorder(root->right);
      cout<<root->value;
}

template<typename type>
treenode<type>* getnode(type data)
{
      treenode<type> *node = new treenode<type>;
      node->value=data;
      node->left=node->right=node->parent=NULL;
      return node;
}

template<typename type>
void insert(treenode<type>* &root,type data)
{
      if(!root)
            root=getnode(data);
      else if(data<=root->value && !root->left)
      {
            treenode<type>* node = getnode(data);
            root->left=node;
            node->parent=root;
      }
      else if(data>root->value && !root->right)
      {
            treenode<type>* node = getnode(data);
            root->right=node;
            node->parent=root;
      }
      else if(data<=root->value && root->left)
            insert(root->left,data);

      else if(data>root->value && root->right)
            insert(root->right,data);
}

template<typename type>
int height(treenode<type> *root)
{
      if(!root->left && !root->right)
            return 0;
      int h1=0,h2=0;
      if(root->right)
            h1=height(root->right);
      if(root->left)
            h2=height(root->left);
      return max(h1,h2)+1;            
}
