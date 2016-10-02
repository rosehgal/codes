#include <bits/stdc++.h>

using namespace std;

void addEdge(list<pair<int,int> >* &g,int u,int v,int w)
{
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}

int mst_prims(list<pair<int,int> > * &g,int nodes)
{
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    int src=0;

    vector<int> dist(nodes,INT_MAX);
    vector<bool> visited(nodes);

    pq.push({0,src});
    dist[src]=0;
    int mst = 0;

    while(!pq.empty())
    {
        int u = pq.top().second;
        visited[u]=true;
        pq.pop();
        for(auto v:g[u])
            if(!visited[v.first] && dist[v.first] > v.second)
            {
                dist[v.first] = v.second;
                pq.push({v.second,v.first});
            }
    }
    for(auto a:dist)
    {
        cout<<a<<" ";
        mst+=a;
    }
    return mst;
}

int main()
{
    int nodes,edges;
    cin>>nodes;
    list<pair<int,int> > *g;
    g=new list<pair<int,int> >[nodes];

    // cin>>edges;
    // while(edges--)
    // {
    //     int u,v,w;
    //     cin>>u>v>>w;
    // }

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


    cout<<mst_prims(g,nodes);
}
