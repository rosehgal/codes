#include <bits/stdc++.h>

using namespace std;

void addEdge(list<pair<int,float> >*& g,int u,int v,float w)
{
    g[u].push_back({v,w});
}
enum color{
    white,gray,black
};
void compute_division(list<pair<int,float> >* &g,int nodes,int src,list<pair<int,float> > *&result_graph)
{

    queue<pair<int,float> > bfs;
    bfs.push({src,1});
    vector<color> visited(nodes,white);
    while(!bfs.empty())
    {
        pair<int,float> p = bfs.front();
        bfs.pop();
        int u = p.first;
        float wt = p.second;
        visited[u]=black;
        cout<<u<<endl;
        for(auto v:g[u])
        {
            if(visited[v.first]==white)
            {
                visited[v.first]=gray;
                bfs.push({v.first,wt*v.second});
                addEdge(result_graph,src,v.first,wt*v.second);
                addEdge(result_graph,v.first,src,(1/(wt*v.second)));
            }
        }
    }
}

int main()
{
    ifstream in("input_eval_division.dat",ios::in);
    int n,m;
    in>>n;
    in>>m;

    cout<<n<<m<<endl;
    list<pair<int,float> > *g = new list<pair<int,float> >[n];
    list<pair<int,float> > *prod_graph,*result_graph;
    prod_graph=new list<pair<int,float> >[n];
    result_graph=new list<pair<int,float> >[n];

    while(m--)
    {
        char a,b;
        float wt;
        in>>a>>b>>wt;
        cout<<a<<b<<wt<<endl;
        addEdge(g,a-'a',b-'a',wt);
    }

    for(int i=0;i<n;++i)
        compute_division(g,n,i,prod_graph);
    char a,b;
    cin>>a>>b;
    compute_division(prod_graph,n,a-'a',result_graph);
    // for(int i=0;i<n;++i)
    // {
    //     //cout<<i;
    //     for(auto v:result_graph[i])
    //         cout<<i<<" -> "<<v.first<<"("<<v.second<<")"<<endl;
    // }

    float result;
    for(auto u:result_graph[a-'a'])
        if(u.first == b-'a')
        {
            result=u.second;
            break;
        }
        
    cout<<result;
    return 0;
}
