#include<iostream>
#include<fstream>
#include"tree.h"
#include <queue>
#include <utility>
#include "linkedlist.hpp"

template<typename type>
vector<node<type>* > get_depth_list(treenode<type>*root)
{
      vector<node<type>*> depth_list(height(root)+1,NULL);
      //cout<<height(root)<<"\n";

      queue<pair<treenode<type>*,int> > queue;
      queue.push(pair<treenode<type>*,int>(root,0));

      while(!queue.empty())
      {
            pair<treenode<type>*,int> temp = queue.front();
            insert(depth_list[temp.second],(temp.first)->value);
            queue.pop();
            if((temp.first)->left)
                  queue.push(pair<treenode<type>*,int>((temp.first)->left,temp.second+1));
            if((temp.first)->right)
                  queue.push(pair<treenode<type>*,int>((temp.first)->right,temp.second+1));
      }

      return depth_list;
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
      for(auto a:get_depth_list(root))
      {
            printlist(a);
            cout<<endl;
      }
      file.close();
      return 0;
}
