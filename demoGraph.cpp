#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void find_levels(list<int>* &g,int n,vector<int> &level){
    queue<pair<int,int>> q;
    q.push({1,1});
    int sum=0;
    while(!q.empty()){
        pair<int,int> curr=q.front();q.pop();
        level[curr.first]=curr.second;
        for(auto v:g[curr.first])
            q.push({v,curr.second+1});
    }
}

int req_sum(list<int> *g,int x,int y,vector<int> nodes,vector<int> level)
{
    queue<int> q;
    q.push(x);
    int sum=0;
    while(!q.empty()){
        int curr=q.front();q.pop();
        if(level[curr]>=y)sum+=nodes[curr-1];
    }
    return sum;
}
int main() {
    int t;
    cin>>t;
    for(int tt=0;tt<t;++tt){
        int n,q;
        cin>>n>>q;
        list<int> *g=new list<int>[n+1];
        vector<int> nodes(n);
        for(int i=0;i<n;++i){
            int x;
            cin>>x;
            nodes[i]=x;
        }
        for(int i=0;i<n-1;++i){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
        }
        vector<int> level(n+1);
        find_levels(g,n,level);
        for(int i=0;i<q;++i)
        {
            int x,y;
            cin>>x>>y;
            cout<<req_sum(g,x,y,nodes,level)<<endl;
        }
    }
    return 0;
}
