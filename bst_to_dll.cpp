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

// template<typename type>
// pair<dllnode<type>*,dllnode<type>*> get_dll_from_bst(treenode<type>* root)
// {
//       if(!root)
//             return pair<dllnode<type>*,dllnode<type>*>(NULL,NULL);
//
//       else if(root && !root->left && !root->right)
//       {
//             std::cout << "The value of the root " <<root->value <<std::endl;
//             dllnode<type>*temp = getnodedll(root->value);
//             return pair<dllnode<type>*,dllnode<type>*>(temp,temp);
//       }
//
//       else
//       {
//             dllnode<type>* mainnode = getnodedll(root->value);
//             cout<<"check1\n";
//             pair<dllnode<type>*,dllnode<type>*> nodes_from_left = get_dll_from_bst(root->left);
//             cout<<"check2\n";
//             (nodes_from_left.second)->next=mainnode;
//             mainnode->prev=nodes_from_left.second;
//             cout<<"check3\n";
//             pair<dllnode<type>*,dllnode<type>*> nodes_from_right = get_dll_from_bst(root->right);
//             cout<<"check4\n";
//             (nodes_from_left.first)->prev=mainnode;
//             cout<<"check5\n";
//             mainnode->next=nodes_from_left.first;
//             return pair<dllnode<type>*,dllnode<type>*>(nodes_from_left.first,nodes_from_right.second);
//       }
// }

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
