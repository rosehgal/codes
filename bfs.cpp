#include <bits/stdc++.h>
using namespace std;


void addEdge(list<pair<int,int> >* &g,int u,int v,int w)
{
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}


enum color{
    white,gray,black
};

void bfs_traversal(list<pair<int,int> > * g,int nodes,int src)
{
    queue<int> bfsq;
    bfsq.push(src);
    vector<color> visited(nodes,white);

    while(!bfsq.empty())
    {
        int u=bfsq.front();
        bfsq.pop();
        visited[u]=black;
        cout<<u<<" ";
        for(auto vw:g[u])
        {
            int v = vw.first;
            if(visited[v]==white)
            {
                bfsq.push(v);
                visited[v]=gray;
            }
        }
    }
}


int main()
{
    int nodes;
    cin>>nodes;
    list<pair<int,int> > *g = new list<pair<int,int> >[nodes];

    addEdge(g,0, 1, 4);
    addEdge(g,0, 7, 8);
    addEdge(g,1, 2, 8);
    addEdge(g,1, 7, 11);
    addEdge(g,2, 3, 7);
    addEdge(g,2, 8, 2);
    addEdge(g,2, 5, 4);
    addEdge(g,3, 4, 9);
    addEdge(g,3, 5, 14);
    addEdge(g,4, 5, 10);
    addEdge(g,5, 6, 2);
    addEdge(g,6, 7, 1);
    addEdge(g,6, 8, 6);
    addEdge(g,7, 8, 7);

    bfs_traversal(g,nodes,0);
    return 0;

}
