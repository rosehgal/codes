#include <bits/stdc++.h>

using namespace std;
struct mycomp{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return b.second<a.second;
    }
};

int min_path(list<pair<int,int> > *g, int nodes=101)
{
    priority_queue<pair<int,int>, vector<pair<int,int> >, mycomp> pq;
    vector<int> dist(nodes,INT_MAX);
    vector<bool> visited(nodes,false);
    int src=1;
    dist[src]=0;
    pq.push({src,0});
    while(!pq.empty()){
        pair<int,int> vertex=pq.top();
        int u = vertex.first,wt=vertex.second;
        visited[u]=true;
        pq.pop();
        for(auto v:g[u])
            if(!visited[v.first]  && dist[v.first] > wt+v.second){
                dist[v.first] = wt+v.second;
                pq.push({v.first,dist[v.first]});
            }
    }
    return dist[100]==INT_MAX?-1:dist[100];
}

int main() {
    int tt;
    cin>>tt;
    for(int t=0;t<tt;++t){
        list<pair<int,int>> *g = new list<pair<int,int>>[101];
        for(int i=1;i<=100;++i)
            for(int j=i+1;j<=i+6 && j<=100;++j)g[i].push_back({j,1});
        int ladders,snakes,a,b;
        cin>>ladders;
        for(int i=0;i<ladders;++i){
            cin>>a>>b;
            g[a].clear();
            g[a].push_back({b,0});
        }
        cin>>snakes;
        for(int i=0;i<snakes;++i){
            cin>>a>>b;
            g[a].clear();
            g[a].push_back({b,0});
        }
        cout<<min_path(g)<<endl;
    }
    return 0;
}
