#include<iostream>
#include<fstream>
#include"tree.h"
#include <queue>
#include <utility>
#include "linkedlist.hpp"

void bst_to_dll(treenode<int> *root,dllnode<int> *&head)
{
      if(!root)
            return;
      bst_to_dll(root->left,head);
      insert(head,root->value);
      bst_to_dll(root->right,head);
}

int main()
{
      treenode<int> *root=NULL;

      ifstream file;
      file.open("treedata.dat",ios::in);

      int count,data;

      file>>count;

      while(count--)
      {
            file >> data;
            insert(root,data);
      }
      inorder(root);
      dllnode<int> *head=NULL;
      bst_to_dll(root,head);
      printlist(head);
      file.close();
      return 0;
}
