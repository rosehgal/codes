#include<iostream>
#include<fstream>
#include"tree.h"
#include "linkedlist.hpp"

template<typename type>
treenode<type>* get_successor(treenode<type> * root)
{
      if(!root->right)
            if(root->parent && root->parent->value > root->value)
                  return root->parent;
            else
                  return NULL;
      treenode<type> *temp = root->right;
      while(temp->left)
            temp=temp->left;
      return temp;
}

int main()
{
      treenode<int> *root=NULL;

      ifstream file;
      file.open("treedata.dat",ios::in);
      int count,data;
      file>>count;
      cout<<count;
      while(count--)
      {
            file >> data;
            insert(root,data);
      }
      inorder(root);
      treenode<int> *succ = get_successor(root->right->right);      
      cout<<endl<<"Root is "<<root->right->right->value<< "and succ is "<<(succ==NULL?-91:succ->value);
      file.close();
      return 0;
}
