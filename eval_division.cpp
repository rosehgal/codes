#include <bits/stdc++.h>

using namespace std;

void addEdge(list<pair<int,float> >*& g,int u,int v,float w)
{
    g[u].push_back({v,w});
}

enum color{
    white,gray,black
};

void compute_division(list<pair<int,float> >* &g,int nodes,int src)
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
        for(auto v:g[u])
        {
            if(visited[v.first]==white)
            {
                visited[v.first]=gray;
                bfs.push({v.first,wt*v.second});
                addEdge(g,src,v.first,wt*v.second);
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

    while(m--)
    {
        char a,b;
        float wt;
        in>>a>>b>>wt;
        cout<<a<<b<<wt<<endl;
        addEdge(g,a-'a',b-'a',wt);
    }

    for(int i=0;i<n;++i)
        compute_division(g,n,i);

        //cout<<"Graph Constructed \n";

    for(int i=0;i<n;++i)
    {
        //cout<<i;
        for(auto v:g[i])
            cout<<i<<" -> "<<v.first<<"("<<v.second<<")"<<endl;
    }

    //query time
    char a,b;
    cin>>a>>b;
    bool rev=false;
    if(a>b)
    {
        rev=true;
        swap(a,b);
    }

    float result;
    for(auto u:g[a-'a'])
        if(u.first == b-'a')
            result=u.second;

    if(rev)
        cout<<(1/result);
    else
        cout<<result;

    return 0;
}
