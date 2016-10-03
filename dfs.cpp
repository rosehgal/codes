#include <bits/stdc++.h>

using namespace std;

enum color{
    white,gray,black
};

vector<color> visited;

void addEdge(list<pair<int,int> > *&graph,int u,int v,int w)
{
    graph[u].push_back({v,w});
    graph[v].push_back({u,w});
}


void dfs(list<pair<int,int> >*g,int src)
{
    if(visited[src] != white)
        return;
    else
    {
        visited[src]=gray;
        for(auto v:g[src])
        {
            if(visited[v.first]==white)
                dfs(g,v.first);
        }
        visited[src]=black;
        cout<<src<<" ";
    }
}

//
// void dfs(list<pair<int,int> > *g, int nodes,int src)
// {
//     vector<color> visited(nodes,white);
//     stack<int> dfsstack();
//
//     dfsstack.push(src);
//     visited[src]=gray;
//
//     while(!dfsstack.empty())
//     {
//         int u = dfsstack.top();
//         visited[u]=black;
//         if(visited[vertex.first]==white)
//         {
//             visited[vertex.first]=gray;
//             dfsstack.push(vertex.first);
//         }
//
//     }
// }


int main()
{
    int nodes;
    cin>>nodes;
    list<pair<int,int> >  *g = new list<pair<int,int> >[nodes];
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
    //addEdge(g,7, 8, 7);

    visited.resize(nodes);
    for(auto &a:visited)
        a=white;

    for(int i=0;i<nodes;++i)
        dfs(g,i);

    return 0;
}
