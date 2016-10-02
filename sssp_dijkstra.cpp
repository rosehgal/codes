#include <bits/stdc++.h>

using namespace std;

void addEdge(list<pair<int,int> >* &g,int u,int v,int w)
{
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}

template <typename type>
struct mycomp
{
    bool operator()(pair<type,type> a,pair<type,type> b)
    {
        return a.second > b.second;
    }

    bool operator()(int a,int b)
    {
        return a<b;
    }
};

vector<int> disjkstra(list<pair<int,int> > *g, int nodes)
{
    priority_queue<pair<int,int>, vector<pair<int,int> >, mycomp<int> > pq;

    vector<int> dist(nodes,INT_MAX);
    vector<bool> visited(nodes,false);

    int src=0;
    dist[src]=0;
    pq.push({src,0});
    while(!pq.empty())
    {
        pair<int,int> vertex=pq.top();
        int u = vertex.first,wt=vertex.second;
        visited[u]=true;
        pq.pop();
        for(auto v:g[u])
        {
            if(!visited[v.first]  && dist[v.first] > wt+v.second)
            {
                dist[v.first] = wt+v.second;
                pq.push({v.first,dist[v.first]});
            }
        }
    }

    return dist;
}

int main()
{
    int nodes=9;
    list<pair<int,int>> *g = new list<pair<int,int> >[nodes];

    // addEdge(g,0,3,5);
    // addEdge(g,0,1,4);
    // addEdge(g,0,2,3);
    // addEdge(g,2,3,1);

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

    for(auto s:disjkstra(g,nodes))
        cout<<s<<" ";
    return 0;
}
