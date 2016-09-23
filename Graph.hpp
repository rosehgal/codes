#include <iostream>
using namespace std;

GraphNode* getNode(int n)
{
    GraphNode *temp= new GraphNode;
    temp->node=n;
    temp->next=NULL;
}


enum color{
    white,grey,black
};

struct GraphNode
{
    int node;
    color nodeColor;
    GraphNode *next;
};


class Graph
{
    GraphNode *adj_list
    int nodes;

public:
    Graph(int nodes)
    {
        this->nodes = nodes;
        adj_list =  new GraphNode[nodes];
        for(int i=0;i<nodes;++i)
            adj_list[i]=NULL;
    }

    color nodeColor(int u)
    {
        return adj_list[u]->nodeColor;
    }

    void add_edge(int u,int v)
    {
        GraphNode *temp = getNode(v),*ptr;
        if(adj_list[u]==NULL)
            adj_list[u]=temp;
        else
        {    while(ptr->next)
                ptr=ptr->next;
            ptr->next=temp;
        }
    }

    void print()
    {
        GraphNode * ptr;
        for(int i=0;i<nodes;++i)
        {
            ptr=adj_list[i];
            while (ptr) {
                cout<<ptr->node<<" ";
            }
            cout<<endl;
        }
    }

    GraphNode * adjacent(int u)
    {
        return adj_list[u];
    }
}
