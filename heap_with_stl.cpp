#include <bits/stdc++.h>

using namespace std;

struct mycomp
{
        bool operator()(pair<int,int>a,pair<int,int>b)
        {
            return a.second < b.second;
        }

        bool operator()(int a,int b)
        {
            return a<b;
        }
};

int main()
{
    priority_queue<int, vector<int> , mycomp > minheap;

    priority_queue<pair<int,int>,vector<pair<int,int> > ,  mycomp >  pair_queue;
    vector<int> vec{2,3,5,4,3,9,1,7,8};

    vector<pair<int,int> > vecpair{{-2, -1}, {2, 1}, {-1, -2}, {-1, 2},{1, -2},  {1, 2}, {2, -1}, {2, 1}};


    for(auto a: vecpair)
        pair_queue.push(a);

        cout<<"Pair before sorting \n";
    // for(auto p: pair_queue)
    //     cout<<p.first <<"," << p.second<<endl;

    while(!pair_queue.empty())
    {
        pair<int,int> p=pair_queue.top();
        cout<<p.first<<","<<p.second<<endl;
        pair_queue.pop();
    }

    sort(p.begin(),p.end(),less)

    for(int i: {2,3,5,4,3,9,1,7,8})
        minheap.push(i);

    while(!minheap.empty())
    {
        cout<<minheap.top();
        minheap.pop();
    }

    for(auto a:vec)
        cout<<a;
    cout<<endl;

    sort(vec.begin(),vec.end(),mycomp<int>());
    sort(vecpair.begin(),vecpair.end(),mycomp<int>());
    for(auto a:vec)
        cout<<a;
    cout<<endl;


    for(auto p : vecpair)
        cout<<p.first<<","<<p.second<<endl;
    return 0;

}
